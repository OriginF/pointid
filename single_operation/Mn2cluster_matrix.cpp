#include "Mn2cluster_matrix.hpp"

int get_cluster_size(EdgeID e_id,int locate){
    int pointid[4];
    EdgeID eRot_id = sub_div.Subdiv2D::rotateEdge(e_id,1);
    if(eRot_id<0)return -1;
    pointid[0] = sub_div.Subdiv2D::edgeOrg(e_id);
    pointid[1] = sub_div.Subdiv2D::edgeDst(e_id);
    pointid[2] = sub_div.Subdiv2D::edgeOrg(e_id);
    pointid[3] = sub_div.Subdiv2D::edgeDst(e_id);
    if(pointid[0]<=0||pointid[1]<=0||pointid[2]<=0||pointid[3]<=0)return -1;
    Point points[4];
    int num1,num2,num3,num4;
    for(int i=0;i<4;i++){
        points[i] = clusters[point2index[pointid[i]]];
    }
    Point center(0,0);
    for(int i=0;i<4;i++){
        center.x += points[i].x;
        center.y += points[i].y;
    }
    center.x/=4;
    center.y/=4;
    switch(locate){
        case 0:{//左上
            int id;
            for(id = 0;id<4;id++){
                if(points[id].x<=center.x&&points[id].y<=center.y){
                    return cluster_size[point2index[pointid[id]]];
                }
            }
        }break;
        case 1:{//右上
            int id;
            for(int id = 0;id<4;id++){
                if(points[id].x<=center.x&&points[id].y>=center.y){
                    return cluster_size[point2index[pointid[id]]];
                }
            }
        }break;
        case 2:{//左下
            int id;
            for(int id = 0;id<4;id++){
                if(points[id].x>=center.x&&points[id].y<=center.y){
                    return cluster_size[point2index[pointid[id]]];
                }
            }
        }
        case 3:{//右下
            int id;
            for(int id = 0;id<4;id++){
                if(points[id].x>=center.x&&points[id].y>=center.y){
                    return cluster_size[point2index[pointid[id]]];
                }
            }
        }
    }
    return -1;
}