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

    for(int i=0;i<SP.cluster_side;i++){
        for(int j=0;j<SP.cluster_side;j++){
            cout << identified_cluster_num[i][j] << " ";
        }
        cout << endl;
    }

    //绘制划分结果
    imshow("output",redraw);

    //系统等待
    waitKey(0);
    system("path");
    getchar();
    return 0;
}
