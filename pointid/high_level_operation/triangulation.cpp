#include "triangulation.hpp"

void triangulation(){
    //Delaunay三角剖分算法
    Rect rect(0, 0, SP.row, SP.col);
    sub_div.initDelaunay(rect);

    //插入点簇
    for(int i=0;i<clusters.size();i++){
        int pointid = sub_div.insert(clusters[i]);
        point2index.insert(pair<int,int>(pointid,i));
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

    NegMatrix<int>* pre_Mn = new NegMatrix<int>[Sn.size()];
    getMn(pre_Mn,Sn);

    Mn = new NegMatrix<int>[Sn.size()];
    for(int i=0;i<Sn.size();i++){
        Mn[i] = pre_Mn[i].calibrate(-1);
    }

    for(int i=0;i<SP.cluster_side;i++){
        for(int j=0;j<SP.cluster_side;j++){
            EdgeID e_id = Mn[0].get_normal(i,j);
            if(e_id == -1)continue;
            Point2f p1,p2;
            int ans1,ans2;
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
    // return Mn;
}