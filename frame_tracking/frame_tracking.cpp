#include "frame_tracking.hpp"

int frame_tracking(){
    tr_parameter_init();
    cout << "start_frame_tracking!" << endl;
    while(!update_clusters_message());
    for(int i=0;i<paper_side;i++){
        for(int j=0;j<paper_side;j++){
            cout <<cluster_num[i][j]<<"("<<cluster_location[i][j]<<")"<< " ";
        }
        cout << endl;
    }
    this_thread::sleep_for(chrono::duration<double>(100000));
    //系统等待
    return 0;
}