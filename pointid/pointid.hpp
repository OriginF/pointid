#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <cmath>
#include <unordered_set>
#include <string>
#include <queue>
#include <thread>

#include "def.hpp"
#include "g_variable.hpp"

#include "single_operation/base_operation.hpp"
#include "single_operation/negMatrix.hpp"
#include "single_operation/delaunay_ext.hpp"
#include "single_operation/Mn_generater.hpp"
#include "single_operation/Mn2cluster_matrix.hpp"

#include "high_level_operation/parameter_init.hpp"
#include "high_level_operation/img_preprocess.hpp"
#include "high_level_operation/point2cluster.hpp"
#include "high_level_operation/triangulation.hpp"
#include "high_level_operation/location_voter.hpp"

using namespace std;
using namespace cv;

#ifndef _POINT_ID_
#define _POINT_ID_

void pointid_run();

int pointid();

#endif