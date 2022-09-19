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
    cout << endl;


    //更新所有点的追踪状态
    update_tracked();

    //输出结果测试
    for(int i=0;i<g_side;i++){
        for(int j=0;j<g_side;j++){
            cout << cluster_num[i][j] << "("<<cluster_location[i][j] << "):"<<(cluster_track[i][j]==S_TRACK::tracked?"tracked":"lost")<<" ";
        }
        cout << endl;
    }
    cout << endl;


    //删去误差点
    false_position_tracking();


    //输出结果测试
    for(int i=0;i<g_side;i++){
        for(int j=0;j<g_side;j++){
            cout << cluster_num[i][j] << "("<<tracked_location[i][j] << "):"<<(cluster_track[i][j]==S_TRACK::tracked?"tracked":"lost")<<" ";
        }
        cout << endl;
    }

    //预测未知点的位置
    interpolation_lost();

    //输出结果测试
    for(int i=0;i<g_side;i++){
        for(int j=0;j<g_side;j++){
            cout << cluster_num[i][j] << "("<<tracked_location[i][j] << "):"<<(cluster_track[i][j]==S_TRACK::tracked?"tracked":"lost")<<" ";
        }
        cout << endl;
    }




    //循环等待程序结束
    this_thread::sleep_for(chrono::duration<double>(100000));
    //系统等待
    return 0;
}