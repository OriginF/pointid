#include "g_variable.hpp"


bool init_done = false;
bool convert_done = false;
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

//画布和三角分割
Mat redraw;
Subdiv2D* sub_div=NULL;

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
NegMatrix<int>* Mn = NULL;

//得到结果的标记
bool identified = false;
//识别点集结果
int** identified_cluster_num=NULL;
int** final_cluster_num=NULL;
Point** identified_cluster_location=NULL;
Point** final_cluster_location=NULL;

//read_done;
bool read_done = false;

//frame index;
int frame_index = 0;