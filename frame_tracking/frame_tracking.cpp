#include "frame_tracking.hpp"

void frame_tracking_run(){
    cout << "start" << endl;
    while(!init_done);
    VideoWriter writer;
    // writer.open("./ans.mp4",CV_FOURCC('M','P','4','2'),30,Size(SP.row,SP.col),true);
    while(!convert_done);

    writer.open("./ans01.avi",VideoWriter::fourcc('M','J','P','G'),25,Size(1000,600),true);
    // cout << "init: "<< SP.row << " " << SP.col << endl;
    if(!writer.isOpened()){cout << "video open error!" << endl;exit(-1);};
    while(!read_done){
        frame_tracking(writer);
    }
    writer.release();
    cout << "frame_tracking done!" << endl;
}

int frame_tracking(VideoWriter writer){
    //初始化全局参数
    clear_parameters();
    tr_parameter_init();

    //检查点是否首次更新完毕
    while(!update_clusters_message());

    // //输出所有的点，进行测试(成功)
    // for(int i=0;i<g_side;i++){
    //     for(int j=0;j<g_side;j++){
    //         cout <<cluster_num[i][j]<<"("<<cluster_location[i][j]<<")"<< " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;


    //更新所有点的追踪状态
    update_tracked();

    // //输出结果测试
    // for(int i=0;i<g_side;i++){
    //     for(int j=0;j<g_side;j++){
    //         cout << cluster_num[i][j] << "("<<cluster_location[i][j] << "):"<<(cluster_track[i][j]==S_TRACK::tracked?"tracked":"lost")<<" ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;


    //删去误差点
    false_position_tracking();


    // //输出结果测试
    // for(int i=0;i<g_side;i++){
    //     for(int j=0;j<g_side;j++){
    //         cout << cluster_num[i][j] << "("<<tracked_location[i][j] << "):"<<(cluster_track[i][j]==S_TRACK::tracked?"tracked":"lost")<<" ";
    //     }
    //     cout << endl;
    // }

    //预测未知点的位置
    interpolation_lost();

    // //输出结果测试
    // for(int i=0;i<g_side;i++){
    //     for(int j=0;j<g_side;j++){
    //         cout << cluster_num[i][j] << "("<<tracked_location[i][j] << "):"<<(cluster_track[i][j]==S_TRACK::tracked?"tracked":"lost")<<" ";
    //     }
    //     cout << endl;
    // }

    //最后绘制一下所有的点簇的点，用来比较
    drawing=Mat(600,1000,CV_8UC3,Scalar(255,255,255));
    for(int i=0;i<g_side;i++){
        for(int j=0;j<g_side;j++){
            circle(drawing,tracked_location[i][j],3,Scalar(0,0,0),1,LINE_8,0);
        }
    }
    //绘制划分结果
    // imshow("output",drawing);
    // // //系统等待
    // waitKey(0);
    // system("path");
    // cout << drawing.cols << " " << drawing.rows << " " << endl;
    writer.write(drawing);

    cout << "cout frame " << out_index++ <<endl;

    //循环等待程序结束
    this_thread::sleep_for(chrono::duration<double>(0.1));
    //系统等待
    return 0;
}