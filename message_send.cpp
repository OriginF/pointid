#include "message_send.hpp"

bool update_clusters_message(){
    if(!identified)return false;
    g_lock.lock();
    for(int i=0;i<paper_side;i++){
        for(int j=0;j<paper_side;j++){
            cluster_num[i][j] = identified_cluster_num[i][j];
            cluster_location[i][j] = identified_cluster_location[i][j];
        }
    }
    g_lock.unlock();
    cout << "1" << endl;
    return true;
}