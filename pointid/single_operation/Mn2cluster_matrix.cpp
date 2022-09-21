#include "Mn2cluster_matrix.hpp"
#include "base_operation.hpp"
#include "../../frame_tracking/g_variable.hpp"

int get_cluster_index(EdgeID e_id,int locate){
    int pointid[4];
    EdgeID to_1 = sub_div->Subdiv2D::getEdge(e_id,Subdiv2D::NEXT_AROUND_LEFT);
    EdgeID to_2 = sub_div->Subdiv2D::getEdge(e_id,Subdiv2D::PREV_AROUND_RIGHT);
    if(to_1>1e7||to_2>1e7||to_1<=0||to_2<=0)return -1;
    pointid[0] = sub_div->Subdiv2D::edgeOrg(e_id);
    pointid[1] = sub_div->Subdiv2D::edgeDst(e_id);
    pointid[2] = sub_div->Subdiv2D::edgeDst(to_1);
    pointid[3] = sub_div->Subdiv2D::edgeDst(to_2);
    if(pointid[0]<=0||pointid[1]<=0||pointid[2]<=0||pointid[3]<=0)return -1;
    Point2f points[4];
    int num1,num2,num3,num4;
    for(int i=0;i<4;i++){
        points[i] = clusters[point2index[pointid[i]]];
    }
    Point2f center(0,0);
    for(int i=0;i<4;i++){
        center.x += points[i].x;
        center.y += points[i].y;
    }
    center.x/=4.0;
    center.y/=4.0;
    float slope[4];
    for(int i=0;i<4;i++){
        slope[i] = (points[i].y-center.y)/(points[i].x-center.x);
    }
    switch(locate){
        case 0:{//左上
            int narrow_id = 0;
            int narrow_slope_delta = 1000;
            for(int id = 0;id<4;id++){
                float slope_delta = abs(1-slope[id]);
                if(narrow_slope_delta>slope_delta&&points[id].x+points[id].y<=center.x+center.y){
                    narrow_id = id;
                    narrow_slope_delta = slope_delta;
                }
            }
            return point2index[pointid[narrow_id]];
        }break;
        case 1:{//右上
            int narrow_id = 0;
            int narrow_slope_delta = 1000;
            for(int id = 0;id<4;id++){
                float slope_delta = abs(-1-slope[id]);
                if(narrow_slope_delta>slope_delta&&center.y+points[id].x<=center.x+points[id].y){
                    narrow_id = id;
                    narrow_slope_delta = slope_delta;
                }
            }
            return point2index[pointid[narrow_id]];
        }break;
        case 2:{//左下
            int narrow_id = 0;
            int narrow_slope_delta = 1000;
            for(int id = 0;id<4;id++){
                float slope_delta = abs(-1-slope[id]);
                if(narrow_slope_delta>slope_delta&&center.x+points[id].y<=center.y+points[id].x){
                    narrow_id = id;
                    narrow_slope_delta = slope_delta;
                }
            }
            return pointid[narrow_id];
        }break;
        case 3:{//右下
            int narrow_id = 0;
            int narrow_slope_delta = 1000;
            for(int id = 0;id<4;id++){
                float slope_delta = abs(1-slope[id]);
                if(narrow_slope_delta>slope_delta&&center.x+center.y<=points[id].x+points[id].y){
                    narrow_id = id;
                    narrow_slope_delta = slope_delta;
                }
            }
            return point2index[pointid[narrow_id]];
        }break;
    }
    return -1;
}

void cluster_generator(int n){
    g_lock.lock();
    if(identified_cluster_location!=NULL){
        for(int i=0;i<SP.cluster_side;i++){
            delete[] identified_cluster_num[i];
            delete[] identified_cluster_location[i];
        }
        delete[] identified_cluster_num;
        delete[] identified_cluster_location;
    }
    identified_cluster_num = new int*[SP.cluster_side];
    identified_cluster_location = new Point*[SP.cluster_side];
    for(int i=0;i<SP.cluster_side;i++){
        identified_cluster_num[i] = new int[SP.cluster_side];
        identified_cluster_location[i] = new Point[SP.cluster_side];
        for(int j=0;j<SP.cluster_side;j++){
            identified_cluster_num[i][j] = -1;
        }
    }
    for(int i=0;i<SP.cluster_side-1;i++){
        for(int j=0;j<SP.cluster_side-1;j++){
            EdgeID e_id = Mn[n].get_normal(i,j);
            if(identified_cluster_num[i][j]==-1){
                int num = get_cluster_index(e_id,0);
                // cout << num << endl;
                if(num!=-1){
                    identified_cluster_num[i][j]=cluster_size[num];
                    identified_cluster_location[i][j]=clusters[num];
                }
            }
            if(identified_cluster_num[i][j+1]==-1){
                int num = get_cluster_index(e_id,1);
                // cout << num << endl;
                if(num!=-1){
                    identified_cluster_num[i][j+1]=cluster_size[num];
                    identified_cluster_location[i][j+1]=clusters[num];
                }
            }
            if(identified_cluster_num[i+1][j]==-1){
                int num = get_cluster_index(e_id,2);
                // cout << num << endl;
                if(num!=-1){
                    identified_cluster_num[i+1][j] = cluster_size[num];
                    identified_cluster_location[i+1][j]=clusters[num];
                }
            }
            if(identified_cluster_num[i+1][j+1]==-1){
                int num = get_cluster_index(e_id,3);
                // cout << num << endl;
                if(num!=-1){
                    identified_cluster_num[i+1][j+1] = cluster_size[num];
                    identified_cluster_location[i+1][j+1]=clusters[num];
                }
            }
        }
    }
    g_lock.unlock();
}