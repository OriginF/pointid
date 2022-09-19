#include "tr_parameter_init.hpp"
#include "../pointid/g_variable.hpp"

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