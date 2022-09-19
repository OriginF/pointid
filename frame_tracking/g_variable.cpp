#include "g_variable.hpp"

int paper_cluster_num[PAPER_SIDE][PAPER_SIDE] = {
    {3,4,1,2,3,1,2,4},
    {2,3,4,3,2,4,1,2},
    {1,4,1,2,4,1,2,3},
    {4,2,4,3,1,4,3,2},
    {2,1,3,4,3,1,4,1},
    {1,3,4,2,1,4,2,3},
    {3,1,3,4,2,1,3,1},
    {2,3,4,1,3,4,1,2}
};

int g_side;

int W_ROI = 5;

mutex** locks;

mutex g_lock;

int paper_side;

int** cluster_num;
Point** cluster_location;

S_TRACK** cluster_track;
Point** tracked_location;

Mat drawing;