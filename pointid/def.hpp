#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

#ifndef _POINT_ID_DEF_
#define _POINT_ID_DEF_

#define RIGHT 0
#define UP 1
#define LEFT 2
#define DOWN 3

#define PAPER_SIDE 8
#define _1_NUM_ 17
#define _2_NUM_ 15
#define _3_NUM_ 16
#define _4_NUM_ 16

typedef int EdgeID;
typedef Vec4f Edge;
typedef pair<int,float> SN;

enum E_locate{
    e_AB,
    e_AD,
    e_CB,
    e_CD,
    e_AC,
    e_DB
};

struct src_param{
    string url;
    float row;
    float col;
    float resolution;
    float Amax;
    float Amin;
    float div;
    int n_kp;
    float d_cl;
    int n_cl;
    float LSE;
    float thet_par;
    float thet_ver;
    int max_edge_id;
    int cluster_side;
};

#endif