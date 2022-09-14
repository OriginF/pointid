#include "pointid.hpp"

int pointid()
{
    //预处理图像参数(来自points.jpg)
    parameter_init();

    //图像读取
    Mat src = imread(SP.url,IMREAD_GRAYSCALE);
    if (src.empty()){
        printf("None Image");
        return -1;
    }


    //按照图片像素得到对应的全局参数的值
    parameter_convert(src);


    //图片降噪
    Mat denoising;
    fastNlMeansDenoising(src,denoising,10,7,21);


    //图像二值化
    Mat bin;
    adaptiveThreshold(denoising,bin,255,THRESH_BINARY_INV,ADAPTIVE_THRESH_GAUSSIAN_C,15,30);


    //连通域、圆心、面积计算
    Mat connect,stats,centroids;
    int nccpmps = connectedComponentsWithStats(
        bin,
        connect,//连通域编号
        stats,//第四维度为面积
        centroids//圆心
    );


    //拿到所有的点集合
    vector<Point> connect_points = get_points(nccpmps,stats,centroids);
    
    //根据点集获取点簇集
    point2cluster(connect_points);


    //Delaunay三角剖分算法加算法划分得到最终的剖分棋盘
    triangulation();

    //生成识别结果的每个位置的点簇结果
    cluster_generator(0);

    //这个原文说可以使用hash优化，不过，我暂时感觉hash优化和我的这个深搜差不多，所以我直接用深搜了
    Point origin = location_voter(identified_cluster_num);

    cout << origin << endl;

    //绘制划分结果
    imshow("output",redraw);

    //系统等待
    waitKey(0);
    system("path");
    getchar();
    return 0;
}
