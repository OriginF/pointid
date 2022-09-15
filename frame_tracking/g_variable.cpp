#include "g_variable.hpp"


int W_ROI = 5;

mutex** locks;

mutex g_lock;

int paper_side;

int** cluster_num;
Point** cluster_location;