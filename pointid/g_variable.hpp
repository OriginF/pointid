#include "def.hpp"
#include "./single_operation/negMatrix.hpp"

#ifndef _POINT_ID_GLOBAL_VAR_
#define _POINT_ID_GLOBAL_VAR_

//初始化完成标记
extern bool init_done;

//画布
extern Mat redraw;

//三角分割
extern Subdiv2D* sub_div;

//表示对应的位置
extern E_locate LOCATE[6];

//记录当前相机的一些处理参数
extern src_param SP,SP_0;

//记录cluster信息
extern vector<Point> clusters;
extern vector<int> cluster_size;

//记录点到cluster对应关系
extern map<int,int> point2index;

//记录所有的边结果Mn
extern NegMatrix<int>* Mn;

//记录整个图像的点的位置和点簇的数目。
extern int init_cluster_num[PAPER_SIDE][PAPER_SIDE];

//记录映射
extern Point L_1[17],L_2[15],L_3[16],L_4[16];


extern bool identified;
extern int** identified_cluster_num;
extern int** final_cluster_num;
extern Point** identified_cluster_location;
extern Point** final_cluster_location;

#endif