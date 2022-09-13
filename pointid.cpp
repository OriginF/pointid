#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <cmath>
#include <unordered_set>
#include <string>
#include <queue>

#include "def.hpp"
#include "g_variable.hpp"

#include "single_operation/base_operation.hpp"
#include "single_operation/negMatrix.hpp"
#include "single_operation/delaunay_ext.hpp"
#include "single_operation/Mn_generater.hpp"
#include "single_operation/Mn2cluster_matrix.hpp"

#include "high_level_operation/parameter_init.cpp"
#include "high_level_operation/img_preprocess.cpp"
#include "high_level_operation/point2cluster.cpp"
#include "high_level_operation/triangulation.cpp"
#include "high_level_operation/location_voter.cpp"

using namespace std;
using namespace cv;

Mat redraw;
Subdiv2D sub_div;

//表示对应的位置
E_locate LOCATE[6];

//记录当前相机的一些处理参数
src_param SP,SP_0;

//记录cluster信息
vector<Point> clusters;
vector<int> cluster_size;

//记录点到cluster对应关系
map<int,int> point2index;

//记录所有的点簇四边形关键边
NegMatrix<int>* Mn;

//点簇设计
int init_cluster_num[PAPER_SIDE][PAPER_SIDE] = {
    {3,4,1,2,3,1,2,4},
    {2,3,4,3,2,4,1,2},
    {1,4,1,2,4,1,2,3},
    {4,2,4,3,1,4,3,2},
    {2,1,3,4,3,1,4,1},
    {1,3,4,2,1,4,2,3},
    {3,1,3,4,2,1,3,1},
    {2,3,4,1,3,4,1,2}
};

Point L_1[_1_NUM_]={
    Point(0,2),Point(0,5),Point(1,6),Point(2,0),Point(2,4),Point(2,5),Point(3,4),Point(4,1),Point(4,5),Point(4,7),Point(5,0),Point(5,4),Point(6,1),Point(6,5),Point(6,7),Point(7,3),Point(7,6)
};
Point L_2[_2_NUM_]={
    Point(0,3),Point(0,6),Point(1,0),Point(1,4),Point(1,7),Point(2,3),Point(2,6),Point(3,1),Point(3,7),Point(4,0),Point(5,3),Point(5,6),Point(6,4),Point(7,0),Point(7,7)
};
Point L_3[_3_NUM_]={
    Point(0,0),Point(0,4),Point(1,1),Point(1,3),Point(2,7),Point(3,3),Point(3,6),Point(4,2),Point(4,4),Point(5,1),Point(5,7),Point(6,0),Point(6,2),Point(6,6),Point(7,1),Point(7,4)
};
Point L_4[_4_NUM_]={
    Point(0,1),Point(0,7),Point(1,2),Point(1,5),Point(2,1),Point(2,4),Point(3,0),Point(3,2),Point(3,5),Point(4,3),Point(4,6),Point(5,2),Point(5,5),Point(6,3),Point(7,2),Point(7,5)
};
int** identified_cluster_num;

int main()
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
    cluster_generator();

    //这个原文说可以使用hash优化，我觉得不需要？
    location_voter(0);

    //绘制划分结果
    imshow("output",redraw);

    //系统等待
    waitKey(0);
    system("path");
    getchar();
    return 0;
}
