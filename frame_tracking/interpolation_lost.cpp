#include "interpolation_lost.hpp"

void interpolation(Point2f& p,int& num,int i1,int j1,int i2,int j2){
    if(cluster_track[i1][j1]==S_TRACK::lost)return;
    if(cluster_track[i2][j2]==S_TRACK::lost)return;
    p.x += 2*cluster_location[i1][j1].x - cluster_location[i2][j2].x;
    p.y += 2*cluster_location[i1][j1].y - cluster_location[i2][j2].y;
    num++;
    return;
}

void interpolation_lost(){
    for(int i=0;i<g_side;i++){
        for(int j=0;j<g_side;j++){
            if(cluster_track[i][j]==S_TRACK::lost){
                Point2f track_l(0.0,0.0);
                int num=0;
                if(i>1)interpolation(track_l,num,i-1,j,i-2,j);
                if(i<g_side-2)interpolation(track_l,num,i+1,j,i+2,j);
                if(j>1)interpolation(track_l,num,i,j-1,i,j-2);
                if(j<g_side-2)interpolation(track_l,num,i,j+1,i,j+2);
                if(i>1&&j>1)interpolation(track_l,num,i-1,j-1,i-2,j-2);
                if(i>1&&j<g_side-2)interpolation(track_l,num,i-1,j+1,i-2,j+2);
                if(i<g_side-2&&j>1)interpolation(track_l,num,i+1,j-1,i+2,j-2);
                if(i<g_side-2&&j<g_side-2)interpolation(track_l,num,i+1,j+1,i+2,j+2);
                track_l.x /= num;
                track_l.y /= num;
                tracked_location[i][j] = track_l;
            }
        }
    }
}