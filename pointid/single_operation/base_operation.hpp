#include "../g_variable.hpp"
#include "../../frame_tracking/g_variable.hpp"

#ifndef _NAME_BASE_OPERATION_
#define _NAME_BASE_OPERATION_

//自定义SN排序算法规则
bool comp(const SN sn_1,const SN sn_2);

//获取两点之间距离的函数
float getDis_p2p(Point A,Point B);

//输出线段的值
void paint_line(Edge l);

//计算模向量乘法
float mod_multi(Edge n1,Edge n2);
float mod_multi(EdgeID e1,EdgeID e2);

//输出线段并绘制
void cout_paint_line(string s,EdgeID e);

//转置
void transpose();

//调整点阵位置
int** reset_matrix(Point origin,int** reset_matrix,int x_side,int y_side);

#endif