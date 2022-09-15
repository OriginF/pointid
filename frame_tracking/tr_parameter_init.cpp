#include "tr_parameter_init.hpp"
#include "../pointid/g_variable.hpp"

void tr_parameter_init(){
    paper_side = CLUSTER_SIDE;
    cluster_location = new Point*[paper_side];
    cluster_num  = new int*[paper_side];
    for(int i=0;i<paper_side;i++){
        cluster_num[i] = new int[paper_side];
        cluster_location[i] = new Point[paper_side];
    }
}