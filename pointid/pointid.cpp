#include "pointid.hpp"

void pointid_run(){
    //预处理图像参数(来自points.jpg)
    parameter_init();

    VideoCapture capture;
    Mat frame;
    capture.open(SP.url);
    if(!capture.isOpened()){cout << "can not open "+SP.url+"\n";exit(10);}
    // capture.read(frame);
    while(capture.read(frame)){
        // cout << 1 <<endl;
        // imshow("output",frame);
        // // waitKey(0);
        pointid(frame);

        // cout << "2" << endl;
    }
    cout << "done every thing!" << endl;
}

int pointid(Mat src)
{
    //转为灰度图像
    Mat gray;
    cvtColor(src,gray,CV_BGR2GRAY);

    //按照图片像素得到对应的全局参数的值
    parameter_convert(gray);
    cout << 1 << endl;
    

    //图片降噪
    Mat denoising;
    fastNlMeansDenoising(gray,denoising,10,7,21);
    cout << 2 << endl;

    //图像二值化
    Mat bin;
    adaptiveThreshold(denoising,bin,255,THRESH_BINARY_INV,ADAPTIVE_THRESH_GAUSSIAN_C,15,30);
    cout << 3 << endl;


    //连通域、圆心、面积计算
    Mat connect,stats,centroids;
    int nccpmps = connectedComponentsWithStats(
        bin,
        connect,//连通域编号
        stats,//第四维度为面积
        centroids//圆心
    );
    cout << 4 << endl;


    //拿到所有的点集合
    vector<Point> connect_points = get_points(nccpmps,stats,centroids);
    cout << 5 << endl;
    
    //根据点集获取点簇集
    point2cluster(connect_points);
    cout << 6 << endl;


    //Delaunay三角剖分算法加算法划分得到最终的剖分棋盘
    triangulation();
    cout << 7 << endl;

    //生成识别结果的每个位置的点簇结果
    cluster_generator(0);
    cout << 8 << endl;

    //矩阵转置
    transpose();
    cout << 9 << endl;

    //这个原文说可以使用hash优化，不过，我暂时感觉hash优化和我的这个深搜差不多，所以我直接用深搜了
    Point origin = location_voter(identified_cluster_num);
    cout << 10 << endl;

    //这一步实现了转置和重定位
    cout << 10.5 << endl;
    g_lock.lock();
    reset_matrix(origin,identified_cluster_num,SP.cluster_side,SP.cluster_side);
    g_lock.unlock();
    cout << 11 << endl;
    
    for(int i=0;i<SP.cluster_side;i++){
        for(int j=0;j<SP.cluster_side;j++){
            cout << final_cluster_num[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    identified = true;

    cout << "pointid done!" << endl;

    //绘制划分结果
    imshow("output",redraw);
    // this_thread::sleep_for(chrono::duration<double>(10));
    //系统等待
    waitKey(0);
    system("path");
    return 0;
}
