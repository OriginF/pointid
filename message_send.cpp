#include "message_send.hpp"

bool update_clusters_message(){
    if(!identified)return false;
    g_lock.lock();
    for(int i=0;i<g_side;i++){
        for(int j=0;j<g_side;j++){
            cluster_num[i][j] = final_cluster_num[i][j];
            cluster_location[i][j] = final_cluster_location[i][j];
        }
    }
    g_lock.unlock();
    return true;
}