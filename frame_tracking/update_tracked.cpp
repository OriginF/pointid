
#include "update_tracked.hpp"

void point_plus(Point2f& point,int& count,int i1,int j1,int i2,int j2){
    if(cluster_track[i1][j1]==S_TRACK::tracked&&cluster_track[i2][j2]==S_TRACK::tracked){
        point.x += (2*cluster_location[i1][j1].x-cluster_location[i2][j2].x);
        point.y += (2*cluster_location[i1][j1].y-cluster_location[i2][j2].y);
        count++;
    }
}

Point2f location_estimate(int i,int j){
    int count=0;
    Point2f ans;
    ans.x = 0.0;
    ans.y = 0.0;
    if(i>1){point_plus(ans,count,i-1,j,i-2,j);};
    if(j>1){point_plus(ans,count,i,j-1,i,j-2);};
    if(i<g_side-2){point_plus(ans,count,i+1,j,i+2,j);};
    if(j<g_side-2){point_plus(ans,count,i,j+1,i,j+2);};
    ans.x/=4.0;
    ans.y/=4.0;
    return ans;
}

void update_tracked(){
    for(int i=0;i<g_side;i++){
        for(int j=0;j<g_side;j++){
            if(cluster_track[i][j] == S_TRACK::tracked){//如果之前识别了这个位置
                if(cluster_num[i][j]!=paper_cluster_num[i][j]){//如果不对应，改为未识别
                    cluster_track[i][j]=S_TRACK::lost;
                }
                else{//对应的话，直接更新对应的坐标。
                    cluster_track[i][j] = S_TRACK::tracked;
                    tracked_location[i][j] = cluster_location[i][j];
                }
            }
            else{//如果未追踪，根据对应附近的点推断当前的点的坐标。
                Point2f p = location_estimate(i,j);
                if(p.x==0&&p.y==0){
                    cluster_track[i][j]=S_TRACK::lost;
                }
                else{
                    cluster_track[i][j]=S_TRACK::tracked;
                    tracked_location[i][j] = p;
                }
            }
        }
    }
}