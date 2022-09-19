#include "frame_tracking.hpp"

int frame_tracking(){
    //初始化全局参数
    tr_parameter_init();

    //检查点是否首次更新完毕
    while(!update_clusters_message());

    //输出所有的点，进行测试(成功)
    for(int i=0;i<g_side;i++){
        for(int j=0;j<g_side;j++){
            cout <<cluster_num[i][j]<<"("<<cluster_location[i][j]<<")"<< " ";
        }
        cout << endl;
    }

    update_tracked();

    for(int i=0;i<g_side;i++){
        for(int j=0;j<g_side;j++){
            cout << cluster_num[i][j] << "("<<cluster_location[i][j] << ")"<<" ";
        }
        cout << endl;
    }

    //循环等待程序结束
    this_thread::sleep_for(chrono::duration<double>(100000));
    //系统等待
    return 0;
}