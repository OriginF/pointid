#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>

#include "def.hpp"
#include "../pointid/def.hpp"

using namespace std;
using namespace cv;

#ifndef _FRAME_TRACKING_GLOBAL_VAR_
#define _FRAME_TRACKING_GLOBAL_VAR_

//表示ROI窗口的大小，原文中设计成了有关t的函数，但是我先设计成常数，后续如果需要我再进行修正
//有点比较奇怪的事情就是目前已经将所有的点簇都抽离出来了，但是这里又做了一次点簇的抽离算法。
extern int W_ROI;

extern int paper_side;


//全局结果
extern int g_side;
extern int paper_cluster_num[PAPER_SIDE][PAPER_SIDE];

//点簇识别传递互斥
extern mutex g_lock;

//点簇识别结果存储
extern int** cluster_num;
extern Point** cluster_location;

extern S_TRACK** cluster_track;
extern Point** tracked_location;

//测试画布
extern Mat drawing;

#endif