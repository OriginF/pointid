#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <cmath>
#include <unordered_set>
#include <string>
#include <queue>

#include "negMatrix.hpp"

using namespace std;
using namespace cv;

#define RIGHT 0
#define UP 1
#define LEFT 2
#define DOWN 3

typedef int EdgeID;
typedef Vec4f Edge;
typedef pair<int,float> SN;

Mat redraw;
Subdiv2D sub_div;

//表示对应的位置
enum E_locate{
    e_AB,
    e_AD,
    e_CB,
    e_CD,
    e_AC,
    e_DB
} LOCATE[6];

//记录当前相机的一些处理参数
struct src_param{
    string url;
    float row;
    float col;
    float resolution;
    float Amax;
    float Amin;
    float div;
    int n_kp;
    float d_cl;
    int n_cl;
    float LSE;
    float thet_par;
    float thet_ver;
    int max_edge_id;
    int cluster_side;
} SP,SP_0;


//自定义SN排序算法规则
bool comp(const SN sn_1,const SN sn_2);

//获取两点之间距离的函数
float getDis_p2p(Point A,Point B);

//输出线段的值
void paint_line(Edge l);

//计算模向量乘法
float mod_multi(Edge n1,Edge n2);

//根据方位获取附近的边ID
EdgeID getNextEdgeID(EdgeID e,E_locate nx);

//根据方位获取附近的边
Edge getNextEdge(EdgeID e,E_locate nx);

//计算L_sq_se
float L_sq_se_calculator(EdgeID e);

//计算Mn
void getMn(NegMatrix<int>* Mn,vector<SN> Sn);

int main()
{
    //预处理图像参数(来自points.jpg)
    SP_0.row = 1374.0;
    SP_0.col = 882.0;
    SP_0.Amax = 80.0;
    SP_0.Amin = 7.0;
    SP_0.div = 111.3;//以此为分割长度,一个里面至多有4个点簇
    SP_0.d_cl = 20;//以此为点簇判定标准,一个点簇至多有四个点
    SP_0.resolution = 1374.0*882.0;
    SP_0.LSE = 0.1;//LSE threshold
    SP_0.thet_par = 0.55;
    SP_0.thet_ver = 0.55;
    SP_0.cluster_side = 9;

    SP.url = "./realimage/real2.jpg";
    // SP.url = "./points.jpg";


    //预处理全局变量
    LOCATE[0] = E_locate::e_CB;
    LOCATE[1] = E_locate::e_CD;
    LOCATE[2] = E_locate::e_AD;
    LOCATE[3] = E_locate::e_AB;
    LOCATE[4] = E_locate::e_AC;
    LOCATE[5] = E_locate::e_DB;


    //图像读取
    Mat src = imread(SP.url,IMREAD_GRAYSCALE);
    if (src.empty()){
        printf("None Image");
        return -1;
    }


    //按照图片像素得到对应的全局参数的值
    SP.row = src.rows;
    SP.col = src.cols;
    SP.resolution = src.rows*src.cols;
    SP.Amax = sqrt(SP.resolution/SP_0.resolution)*SP_0.Amax;
    SP.Amin = sqrt(SP.resolution/SP_0.resolution)*SP_0.Amin;
    SP.div = sqrt(SP.resolution/SP_0.resolution)*SP_0.div;
    SP.d_cl = sqrt(SP.resolution/SP_0.resolution)*SP_0.d_cl;
    SP.n_kp = 16;
    SP.n_cl = 4;
    SP.LSE = SP_0.LSE;
    SP.thet_par = SP_0.thet_par;
    SP.thet_ver = SP_0.thet_ver;
    SP.cluster_side = SP_0.cluster_side;
    // cout << SP.Amax << " "  << SP.Amin << " " << SP.div << endl;


    //图片降噪
    Mat denoising;
    fastNlMeansDenoising(src,denoising,10,7,21);


    //图像二值化
    Mat bin;
    adaptiveThreshold(denoising,bin,255,THRESH_BINARY_INV,ADAPTIVE_THRESH_GAUSSIAN_C,15,30);


    //连通域、圆心、面积计算
    Mat connect,stats,centroids;
    int nccpmps = connectedComponentsWithStats(
        bin,
        connect,//连通域编号
        stats,//第四维度为面积
        centroids//圆心
    );


    //拿到所有的点集合
    vector<Point> connect_points;
    for(int i=1;i<nccpmps;i++){
        if(stats.at<int>(i,CC_STAT_AREA)>SP.Amin&&stats.at<int>(i,CC_STAT_AREA)<SP.Amax){
            connect_points.push_back(Point(centroids.at<Vec2d>(i,0)));
        }
    }


    //输出数据调试
    // cout << "连通域数："<<nccpmps<<endl;
    // for(int i=0;i<nccpmps;i++){
    //     cout << "第"<<i<<"个连通域:面积:"<<stats.at<int>(i,CC_STAT_AREA)<<" 圆心："<<centroids.at<Vec2d>(i,0)<<endl;
    // }
    // imshow("ImputImage",bin);


    //添加网格分割
    redraw=Mat(SP.row,SP.col,CV_8UC3,Scalar(255,255,255));
    int row_num = SP.row/SP.div;
    int col_num = SP.col/SP.div;
    for(int i=0;i<=row_num;i++){
        line(redraw,Point(0,i*SP.div),Point(SP.col,i*SP.div),Scalar(0,0,0));
    }
    for(int i=0;i<=col_num;i++){
        line(redraw,Point(i*SP.div,0),Point(i*SP.div,SP.row),Scalar(0,0,0));
    }


    //点簇分割,这个原来的论文里面没有讲,但是我觉得可以加上,效果会更好,可以省去大量的计算
    vector<int> cluster_counter;
    vector<Point> cluster_center;
    vector<int> point2cluster;
    for(int i=0;i<connect_points.size();i++){
        bool new_cluster=true;
        for(int j=0;j<i;j++){
            if(getDis_p2p(connect_points[i],connect_points[j])<SP.d_cl){
                point2cluster.push_back(point2cluster[j]);
                cluster_counter[point2cluster[j]]++;
                cluster_center[point2cluster[j]].x+=connect_points[i].x;
                cluster_center[point2cluster[j]].y+=connect_points[i].y;
                new_cluster = false;
                break;
            }
        }
        if(new_cluster){
            cluster_counter.push_back(1);
            cluster_center.push_back(Point(connect_points[i]));
            point2cluster.push_back(cluster_counter.size()-1);
        }
    }
    for(int i=0;i<cluster_center.size();i++){
        cluster_center[i].x/=cluster_counter[i];
        cluster_center[i].y/=cluster_counter[i];
    }
    assert(point2cluster.size()==connect_points.size());
    
    
    //这里已经拿到了所有的cluster，现在尝试对cluster进行分割
    //开始遍历点和网格分割(这没想好,但是感觉复杂度挺高的,O(n^2*m),n表示点的个数,m表示方格的个数),删除方格内超过16个的点的方格
    vector<int>** grid_queue = new vector<int>*[row_num+1];
    for(int i=0;i<=row_num;i++){
        grid_queue[i] = new vector<int>[col_num+1];
    }
    for(int point=0;point<connect_points.size();point++){
        Point p(connect_points[point]);
        for(float i=0;i<=row_num;i++){
            if(p.x>=i*SP.div&&p.x<=(i+1)*SP.div){
                for(float j=0;j<=col_num;j++){
                    if(p.y>=j*SP.div&&p.y<=(j+1)*SP.div){
                        grid_queue[int(i)][int(j)].push_back(point);
                    }
                }
            }
        }
    }
    

    vector<Point> grid_points;
    vector<int> point_id;
    vector<Point> temp_clusters;
    for(float i=0;i<=row_num;i++){
        for(float j=0;j<=col_num;j++){
            vector<int> grid_q = grid_queue[int(i)][int(j)];
            set<int> cl_set;
            for(int point=0;point<grid_q.size();point++){
                cl_set.insert(point2cluster[grid_q[point]]);
            }
            if(grid_q.size()<=cl_set.size()*4){
                for(int q:grid_q){
                    grid_points.push_back(connect_points[q]);
                    point_id.push_back(q);
                }
            }
        }
    }
    for(int i=0;i<point_id.size();i++){
        Point center = cluster_center[point2cluster[point_id[i]]];
        temp_clusters.push_back(center);
    }

    vector<Point> clusters;
    for(int i=0;i<temp_clusters.size();i++){
        bool new_point=true;
        for(int j=0;j<i;j++){
            if(temp_clusters[i]==temp_clusters[j]){
                new_point= false;
                break;
            }
        }
        if(new_point){
            clusters.push_back(temp_clusters[i]);
        }
    }
    

    //单个点簇不能太大
    // vector<Point> cluster_points;
    // for(int i=0;i<grid_points.size();i++){
    //     if(cluster_counter[point2cluster[i]]<=SP.n_cl){
    //         cluster_points.push_back(connect_points[i]);
    //     }
    // }


    //Delaunay三角剖分算法
    Rect rect(0, 0, SP.row, SP.col);
    sub_div.initDelaunay(rect);
    map<int,int> point2index;

    //插入点簇
    for(int i=0;i<clusters.size();i++){
        int pointid = sub_div.insert(clusters[i]);
    }

    //拿到所有的边的集合（这里只是视觉呈现，并不必要
    vector<Vec4f> edgeList;
    sub_div.Subdiv2D::getEdgeList(edgeList);
    vector<int> leadingEdgeList;
    sub_div.Subdiv2D::getLeadingEdgeList(leadingEdgeList);
    for(int i=0;i<edgeList.size();i++){
        Point p1(edgeList[i][0],edgeList[i][1]),p2(edgeList[i][2],edgeList[i][3]);
        // line(redraw,p1,p2,Scalar(255,0,0),1,LINE_8,0);
    }
    //到此位置可以注释
    SP.max_edge_id = 0;

    //绘制所有的主边
    for(int i=0;i<leadingEdgeList.size();i++){
        EdgeID id = leadingEdgeList[i];
        if(id>SP.max_edge_id)SP.max_edge_id = id;
        Point2f p1,p2;
        int ans1 = sub_div.Subdiv2D::edgeDst(id,&p1);
        int ans2 = sub_div.Subdiv2D::edgeOrg(id,&p2);
        if(ans1>0&&ans2>0){
            // line(redraw,p1,p2,Scalar(0,255,0));
        }
    }

    //尝试计算所有的主边的Lsq_se
    vector<SN> Sn; 
    for(int i=0;i<leadingEdgeList.size();i++){
        int id = leadingEdgeList[i];
        float Lsq_se = L_sq_se_calculator(id);
        if(Lsq_se>SP.LSE){
            Sn.push_back(SN(id,Lsq_se));
        }
    }

    

    //根据LSE的值进行排序
    sort(Sn.begin(),Sn.end(),comp);
    
    int id = Sn[0].first;
    Point2f p1,p2;
    int ans1 = sub_div.Subdiv2D::edgeDst(id,&p1);
    int ans2 = sub_div.Subdiv2D::edgeOrg(id,&p2);
    line(redraw,p1,p2,Scalar(255,255,0));

    // int*** Mn = new int**[Sn.size()];
    NegMatrix<int>* Mn = new NegMatrix<int>[Sn.size()];
    getMn(Mn,Sn);

    for(int i=0;i<SP.cluster_side;i++){
        for(int j=0;j<SP.cluster_side;j++){
            EdgeID e_id = Mn[0].get_normal(i,j);
            if(e_id == -1)continue;
            Point2f p1,p2;
            int ans1,ans2;
            // cout << e_id << endl;
            EdgeID AB_id = getNextEdgeID(e_id,E_locate::e_AB);
            ans1 = sub_div.Subdiv2D::edgeDst(AB_id,&p1);
            ans2 = sub_div.Subdiv2D::edgeOrg(AB_id,&p2);
            if(ans1>0&&ans2>0){
                line(redraw,p1,p2,Scalar(255,100,100));
            }
            EdgeID AD_id = getNextEdgeID(e_id,E_locate::e_AD);
            ans1 = sub_div.Subdiv2D::edgeDst(AD_id,&p1);
            ans2 = sub_div.Subdiv2D::edgeOrg(AD_id,&p2);
            if(ans1>0&&ans2>0){
                line(redraw,p1,p2,Scalar(255,100,100));
            }
            EdgeID CB_id = getNextEdgeID(e_id,E_locate::e_CB);
            ans1 = sub_div.Subdiv2D::edgeDst(CB_id,&p1);
            ans2 = sub_div.Subdiv2D::edgeOrg(CB_id,&p2);
            if(ans1>0&&ans2>0){
                line(redraw,p1,p2,Scalar(255,100,100));
            }
            EdgeID CD_id = getNextEdgeID(e_id,E_locate::e_CD);
            ans1 = sub_div.Subdiv2D::edgeDst(CD_id,&p1);
            ans2 = sub_div.Subdiv2D::edgeOrg(CD_id,&p2);
            if(ans1>0&&ans2>0){
                line(redraw,p1,p2,Scalar(255,100,100));
            }
        }
    }

    // Point2f p1,p2;
    // int id = leadingEdgeList[20];
    // int ans1 = sub_div.Subdiv2D::edgeDst(id,&p1);
    // int ans2 = sub_div.Subdiv2D::edgeOrg(id,&p2);
    // if(ans1>0&&ans2>0){
    //     cout << "legal" << endl;
    //     circle(redraw,p1,3,Scalar(0,0,255),10,LINE_8,0);
    //     circle(redraw,p2,3,Scalar(0,0,255),10,LINE_8,0);
    //     line(redraw,p1,p2,Scalar(0,255,0));
    // }
    // L_sq_se_calculator(id,sub_div);


    for(Point p:grid_points){
        circle(redraw,p,3,Scalar(0,0,0),1,LINE_8,0);
    }
    imshow("output",redraw);

    //系统等待
    waitKey(0);
    system("path");
    getchar();
    return 0;
}


bool comp(const SN sn_1,const SN sn_2){
    if(sn_1.second>sn_2.second)return true;
    else return false;
}


float getDis_p2p(Point A,Point B){
    return sqrt(pow((A.x-B.x),2)+pow((A.y-B.y),2));
}


void paint_line(Edge l){
    Point p1(l[0],l[1]),p2(l[2],l[3]);
    line(redraw,p1,p2,Scalar(0,255,0));
}


float mod_multi(Edge n1,Edge n2){
    float mod1 = sqrt(pow(n1[3]-n1[1],2)+pow(n1[2]-n1[0],2));
    float mod2 = sqrt(pow(n2[3]-n2[1],2)+pow(n2[2]-n2[0],2));
    float multi = (n1[3]-n1[1])*(n2[3]-n2[1])+(n1[2]-n1[0])*(n2[2]-n2[0]);
    return multi/(mod1*mod2);
}


float mod_multi(EdgeID e1,EdgeID e2){
    Point2f p01,p02,p11,p12;
    sub_div.Subdiv2D::edgeOrg(e1,&p01);
    sub_div.Subdiv2D::edgeDst(e1,&p02);
    Edge n1 = Edge(p01.x,p01.y,p02.x,p02.y);
    sub_div.Subdiv2D::edgeOrg(e2,&p11);
    sub_div.Subdiv2D::edgeDst(e2,&p12);
    Edge n2 = Edge(p11.x,p11.y,p12.x,p12.y);
    return mod_multi(n1,n2);
}

E_locate CB_CD_AD_AB_maper(EdgeID e,int l){
    Point2f org,dst;
    int organs = sub_div.Subdiv2D::edgeOrg(e,&org);
    int dstans = sub_div.Subdiv2D::edgeDst(e,&dst);
    if(org.x<=dst.x){
        if(org.y<=dst.y){
            switch(l){
                case RIGHT:return E_locate::e_CB;
                case UP:return E_locate::e_CD;
                case LEFT:return E_locate::e_AD;
                case DOWN:return E_locate::e_AB;
                default:cout << "wrong locate" << endl;exit(4);
            }
        }
        else{
            switch(l){
                case RIGHT:return E_locate::e_CD;
                case UP:return E_locate::e_AD;
                case LEFT:return E_locate::e_AB;
                case DOWN:return E_locate::e_CB;
                default:cout << "wrong locate" << endl;exit(4); 
            }
        }
    }
    else{
        if(org.y<=dst.y){
            switch(l){
                case RIGHT:return E_locate::e_AB;
                case UP:return E_locate::e_CB;
                case LEFT:return E_locate::e_CD;
                case DOWN:return E_locate::e_AD;
                default:cout << "wrong locate" << endl;exit(4);
            }
        }
        else{
            switch(l){
                case RIGHT:return E_locate::e_AD;
                case UP:return E_locate::e_AB;
                case LEFT:return E_locate::e_CB;
                case DOWN:return E_locate::e_CD;
                default:cout << "wrong locate" << endl;exit(4);
            }
        }
    }
    return E_locate::e_AC;
}


EdgeID getNextEdgeID(EdgeID e,E_locate nx){
    EdgeID ans_id;
    switch(nx){
        case E_locate::e_AB:{
            ans_id = sub_div.Subdiv2D::getEdge(e,Subdiv2D::NEXT_AROUND_DST);
            return ans_id;
        }
        case E_locate::e_AD:{
            ans_id = sub_div.Subdiv2D::getEdge(e,Subdiv2D::NEXT_AROUND_RIGHT);
            return ans_id;
        }
        case E_locate::e_CB:{
            ans_id = sub_div.Subdiv2D::getEdge(e,Subdiv2D::PREV_AROUND_DST);
            return ans_id;
        }
        case E_locate::e_CD:{
            ans_id = sub_div.Subdiv2D::getEdge(e,Subdiv2D::PREV_AROUND_LEFT);
            return ans_id;
        }
        case E_locate::e_DB:{
            return e;
        }
        case E_locate::e_AC:{
            ans_id = sub_div.Subdiv2D::rotateEdge(e,1);
            return ans_id;
        }
        default:cout << "wrong nx" << endl;exit(5);
    }
    return ans_id;
}


Edge getNextEdge(EdgeID e,E_locate nx){
    EdgeID e_l_id= getNextEdgeID(e,nx);
    Point2f org,dst;
    int organs = sub_div.Subdiv2D::edgeOrg(e_l_id,&org);
    int dstans = sub_div.Subdiv2D::edgeDst(e_l_id,&dst);
    return Edge(org.x,org.y,dst.x,dst.y);
}


float L_sq_se_calculator(EdgeID e){
    Point2f p1,p2;
    EdgeID AB_id = sub_div.Subdiv2D::getEdge(e,Subdiv2D::NEXT_AROUND_DST);
    sub_div.Subdiv2D::edgeOrg(AB_id,&p1);
    sub_div.Subdiv2D::edgeDst(AB_id,&p2);
    Edge AB(p1.x,p1.y,p2.x,p2.y);
    EdgeID AD_id = sub_div.Subdiv2D::getEdge(e,Subdiv2D::NEXT_AROUND_RIGHT);
    sub_div.Subdiv2D::edgeOrg(AD_id,&p1);
    sub_div.Subdiv2D::edgeDst(AD_id,&p2);
    Edge AD(p1.x,p1.y,p2.x,p2.y);
    EdgeID CB_id = sub_div.Subdiv2D::getEdge(e,Subdiv2D::PREV_AROUND_DST);
    sub_div.Subdiv2D::edgeOrg(CB_id,&p1);
    sub_div.Subdiv2D::edgeDst(CB_id,&p2);
    Edge CB(p1.x,p1.y,p2.x,p2.y);
    EdgeID CD_id = sub_div.Subdiv2D::getEdge(e,Subdiv2D::PREV_AROUND_LEFT);
    sub_div.Subdiv2D::edgeOrg(CD_id,&p1);
    sub_div.Subdiv2D::edgeDst(CD_id,&p2);
    Edge CD(p1.x,p1.y,p2.x,p2.y);
    Edge AC(AB[0],AB[1],CB[0],CB[1]);
    Edge DB(CD[2],CD[3],CB[2],CB[3]);
    float Lsq_se=1.0
        -1.0/3.0*pow(mod_multi(AB,AD),2)
        -1.0/3.0*pow(mod_multi(CB,CD),2)
        -1.0/3.0*pow(mod_multi(AC,DB),2);
    return Lsq_se;
}


int condition_Judger(EdgeID e){
    Edge AB = getNextEdge(e,E_locate::e_AB);
    Edge AD = getNextEdge(e,E_locate::e_AD);
    Edge CB = getNextEdge(e,E_locate::e_CB);
    Edge CD = getNextEdge(e,E_locate::e_CD);
    int ans = 0;
    // cout << mod_multi(AD,CB) << endl;
    if(1-pow(mod_multi(AB,CD),2)<SP.thet_par
      &&1-pow(mod_multi(AD,CB),2)<SP.thet_par){
        ans|=1;
    }
    if(pow(mod_multi(AD,CD),2)<SP.thet_ver
        &&1-pow(mod_multi(AB,CB),2)<SP.thet_par){
            ans|=2;
    }
    return ans;
}


EdgeID get_eBar(EdgeID e,int locate){
    E_locate ans_locate = CB_CD_AD_AB_maper(e,locate);
    switch(ans_locate){
        case E_locate::e_CB: case E_locate::e_CD:
        {
            Edge DB = getNextEdge(e,E_locate::e_DB);
            Edge CB = getNextEdge(e,E_locate::e_CB);
            Edge CD = getNextEdge(e,E_locate::e_CD);
            float mod_cos_CB_DB = abs(mod_multi(CB,DB));
            float mod_cos_CD_DB = abs(mod_multi(CD,DB));
            if(mod_cos_CB_DB < mod_cos_CD_DB){
                return getNextEdgeID(e,E_locate::e_CD);
            }
            else{
                return getNextEdgeID(e,E_locate::e_CB);
            }
        }break;
        case E_locate::e_AB: case E_locate::e_AD:
        {
            Edge AB = getNextEdge(e,E_locate::e_AB);
            Edge AD = getNextEdge(e,E_locate::e_AD);
            Edge DB = getNextEdge(e,E_locate::e_DB);
            float mod_cos_AB_DB = abs(mod_multi(AB,DB));
            float mod_cos_AD_DB = abs(mod_multi(AD,DB));
            if(mod_cos_AB_DB < mod_cos_AD_DB){
                return getNextEdgeID(e,E_locate::e_AD);
            }
            else{
                return getNextEdgeID(e,E_locate::e_AB);
            }
        }break;
        default:{
            cout << "wrong locate num" << endl;
            exit(3);
        }
    }
    return -1;
}


void cout_paint_line(string s,EdgeID e){
    Point2f org,dst;
    int organs = sub_div.Subdiv2D::edgeOrg(e,&org);
    int dstans = sub_div.Subdiv2D::edgeDst(e,&dst);
    line(redraw,org,dst,Scalar(0,255,0));
    cout << s <<":["<<org<<","<<dst<<"]"<<endl;
}


void getMn(NegMatrix<int>* Mn,vector<SN> Sn){
    for(int i=0;i<Sn.size();i++){//这里的这个Mn的大小实际上是需要我们进行一个优化，但是我还没有考虑好空间的上界，目前先设立成这个大小。
        Mn[i].reset(SP.cluster_side,SP.cluster_side,-1);
    }
    vector<bool> Sn_mark(SP.max_edge_id,false);//这里感觉还是有一点奇怪的，因为此处实际上是开始只设立一个mark，但是要重复对每个点进行一次考虑。
    for(int n=0;n<Sn.size();n++){
        if(!Sn_mark[Sn[n].first]){
            Sn_mark[Sn[n].first] = true;
            Mn[n].set(0,0,Sn[n].first);
            queue<pair<EdgeID,Point>> Q;
            Q.push(pair<EdgeID,Point>(Sn[n].first,Point(0,0)));
            int counter = 0;
            while(!Q.empty()){
                counter++;
                EdgeID id = Q.front().first;
                Point p = Q.front().second;
                Q.pop();
                for(int l=0;l<=3;l++){
                    E_locate l_locate = CB_CD_AD_AB_maper(id,l);
                    EdgeID e_id = getNextEdgeID(id,l_locate);
                    Point2f p01,p02;
                    int ans1 = sub_div.Subdiv2D::edgeDst(e_id,&p01);
                    int ans2 = sub_div.Subdiv2D::edgeOrg(e_id,&p02);
                    int condition_ans = condition_Judger(e_id);
                    if(condition_ans>0){//这个地方变成的可能不是原来的那个边，很奇怪（有可能覆盖原来的位置
                        EdgeID eBar_id = get_eBar(e_id,l);
                        Point eBar_p;
                        int eBar_condition_ans = condition_Judger(eBar_id);
                        float cos = abs(mod_multi(id,eBar_id));
                        if(cos>0.80&&cos<1-1e-3){continue;};//这个地方很奇怪，在所有的情况下，cos都应该小于1
                        if(!Sn_mark[eBar_id]&&((eBar_condition_ans&1)>0)){//现在每种情况下，这里只会在单个地方进行访问？
                            switch(l){
                                case 0:
                                    eBar_p = Point(p.x,p.y+1);
                                    // if(p.y+1>=SP.cluster_side)continue;
                                    Mn[n].set(p.x,p.y+1,eBar_id);
                                    break;
                                case 1:
                                    eBar_p = Point(p.x-1,p.y);
                                    // if(p.x-1<0)continue;
                                    Mn[n].set(p.x-1,p.y,eBar_id);
                                    break;
                                case 2:
                                    eBar_p = Point(p.x,p.y-1);
                                    // if(p.y-1<0)continue;
                                    Mn[n].set(p.x,p.y-1,eBar_id);
                                    break;
                                case 3:
                                    eBar_p = Point(p.x+1,p.y);
                                    // if(p.x+1>=SP.cluster_side)continue;
                                    Mn[n].set(p.x+1,p.y,eBar_id);
                                    break;
                                default:
                                    cout << "wrong l num"<< endl;
                                    exit(-2);
                            }
                            Point2f p1,p2;
                            int ans1 = sub_div.Subdiv2D::edgeDst(eBar_id,&p1);
                            int ans2 = sub_div.Subdiv2D::edgeOrg(eBar_id,&p2);
                            Q.push(pair<EdgeID,Point>(eBar_id,eBar_p));
                            Sn_mark[eBar_id] = true;
                            EdgeID rotate_eBar_id = sub_div.Subdiv2D::rotateEdge(eBar_id,2);
                            Sn_mark[rotate_eBar_id] = true;
                        }
                    }
                }
            }
        }
    }
}