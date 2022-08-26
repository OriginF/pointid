#include <opencv2/opencv.hpp>
#include <iostream>
#include <cmath>
#include <string>

using namespace std;
using namespace cv;

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
} SP,SP_0;


//获取两点之间距离的函数
float getDis_p2p(Point A,Point B);


int main()
{
    //预处理图像参数(来自points.jpg)
    SP_0.row = 1374.0;
    SP_0.col = 882.0;
    SP_0.Amax = 80.0;
    SP_0.Amin = 7.0;
    SP_0.div = 111.3;//以此为分割长度,一个里面至多有4个点簇
    SP_0.d_cl = 10;//以此为点簇判定标准,一个点簇至多有四个点
    SP_0.resolution = 1374.0*882.0;


    SP.url = "./realimage/real2.jpg";
    // SP.url = "./points.jpg";


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
    cout << SP.Amax << " "  << SP.Amin << " " << SP.div << endl;


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


    //输出数据调试
    // cout << "连通域数："<<nccpmps<<endl;
    // for(int i=0;i<nccpmps;i++){
    //     cout << "第"<<i<<"个连通域:面积:"<<stats.at<int>(i,CC_STAT_AREA)<<" 圆心："<<centroids.at<Vec2d>(i,0)<<endl;
    // }
    // imshow("ImputImage",bin);


    //添加网格分割
    Mat redraw(SP.row,SP.col,CV_8UC3,Scalar(255,255,255));
    int row_num = SP.row/SP.div;
    int col_num = SP.col/SP.div;
    cout << row_num << " " << col_num << endl;
    cout << SP.row << " " << SP.col << endl;
    for(int i=0;i<=row_num;i++){
        line(redraw,Point(0,i*SP.div),Point(SP.col,i*SP.div),Scalar(0,0,0));
    }
    for(int i=0;i<=col_num;i++){
        line(redraw,Point(i*SP.div,0),Point(i*SP.div,SP.row),Scalar(0,0,0));
    }


    // 开始遍历点和网格分割(这没想好,但是感觉复杂度挺高的,O(n^2*m),n表示点的个数,m表示方格的个数),删除方格内超过16个的点的方格
    int **point_counter = new int*[row_num+1];
    Point point_locate[nccpmps];
    for(int row = 0;row<=row_num;row++){
        point_counter[row] = new int[col_num+1];
        for(int col = 0;col<=col_num;col++){
            point_counter[row][col] = 0;
        }
    }
    for(int point=1;point<nccpmps;point++){
        Point p(centroids.at<Vec2d>(point,0));
        if(stats.at<int>(point,CC_STAT_AREA)>SP.Amin&&stats.at<int>(point,CC_STAT_AREA)<SP.Amax){
            for(float grid_row = 0;grid_row<SP.row;grid_row+=SP.div){
                if(p.x>grid_row&&p.x<grid_row+SP.div){
                    for(float grid_col = 0;grid_col<SP.col;grid_col+=SP.div){
                        if(p.y>grid_col&&p.y<grid_col+SP.div){
                            point_counter[int(grid_row/SP.div)][int(grid_col/SP.div)]+=1;
                            point_locate[point] = Point(grid_row/SP.div,grid_col/SP.div);
                        }
                    }
                }
            }
        }
        else{
            point_locate[point] = Point(-1,-1);
        }
    }
    vector<Point> grid_points;
    for(int point = 1;point<nccpmps;point++){
        Point p(point_locate[point]);
        if(p.x>0&&p.y>0){
            if(point_counter[int(point_locate[point].x)][int(point_locate[point].y)]<=SP.n_kp){
                grid_points.push_back(Point(centroids.at<Vec2d>(point,0)));
            }
        }
    }

    
    //点簇分割,这个原来的论文里面没有讲,但是我觉得可以加上,效果会更好,可以省去大量的计算(当前我做的是最短路算法的,后续有时间可以改成画圆包裹计算的)
    vector<int> cluster_counter;
    vector<int> cluster_hash;
    for(int i=0;i<grid_points.size();i++){
        bool new_cluster=true;
        for(int j=0;j<i;j++){
            if(getDis_p2p(grid_points[i],grid_points[j])<SP.d_cl){
                cluster_hash.push_back(cluster_hash[j]);
                cluster_counter[cluster_hash[j]]++;
                new_cluster = false;
                break;
            }
        }
        if(new_cluster){
            cluster_counter.push_back(1);
            cluster_hash.push_back(cluster_counter.size()-1);
        }
    }
    assert(cluster_hash.size()==grid_points.size());
    vector<Point> cluster_points;
    for(int i=0;i<grid_points.size();i++){
        if(cluster_counter[cluster_hash[i]]<=SP.n_cl){
            cluster_points.push_back(grid_points[i]);
        }
    }


    //原图复制
    // Mat redraw(src.rows,src.cols,CV_8UC3,Scalar(255,255,255));
    // for(int i=1;i<nccpmps;i++){//每个位置是一个黑点
    //     if(stats.at<int>(i,CC_STAT_AREA)>SP.Amin&&stats.at<int>(i,CC_STAT_AREA)<SP.Amax){
    //         circle(redraw,Point(centroids.at<Vec2d>(i,0)),3,Scalar(0,0,0),1,LINE_8,0);
    //     }
    // }
    for(Point p:cluster_points){
        circle(redraw,p,3,Scalar(0,0,0),1,LINE_8,0);
    }
    imshow("output",redraw);

    //系统等待
    waitKey(0);
    system("path");
    getchar();
    return 0;
}

float getDis_p2p(Point A,Point B){
    return sqrt(pow((A.x-B.x),2)+pow((A.y-B.y),2));
}