#include "tr_parameter_init.hpp"
#include "../pointid/g_variable.hpp"

void clear_parameters(){
    if(cluster_location!=NULL){
        for(int i=0;i<g_side;i++){
            delete[] cluster_location[i];
        }
        delete[] cluster_location;
    }
    if(cluster_num!=NULL){
        for(int i=0;i<g_side;i++){
            delete[] cluster_num[i];
        }
        delete[] cluster_num;
    }
    if(cluster_track!=NULL){
        for(int i=0;i<g_side;i++){
            delete[] cluster_track[i];
        }
        delete[] cluster_track;
    }
    if(tracked_location!=NULL){
        for(int i=0;i<g_side;i++){
            delete[] tracked_location[i];
        }
        delete[] tracked_location;
    }
}

void tr_parameter_init(){
    g_side = PAPER_SIDE;
    paper_side = CLUSTER_SIDE;
    cluster_location = new Point*[g_side];
    cluster_num  = new int*[g_side];
    for(int i=0;i<g_side;i++){
        cluster_num[i] = new int[paper_side];
        cluster_location[i] = new Point[paper_side];
    }
    cluster_track = new S_TRACK*[g_side];
    tracked_location = new Point*[g_side];
    for(int i=0;i<g_side;i++){
        cluster_track[i] = new S_TRACK[g_side];
        tracked_location[i] = new Point[g_side];
        for(int j=0;j<g_side;j++){
            cluster_track[i][j] = S_TRACK::tracked;
            tracked_location[i][j] = Point(0,0);
        }
    }
}