#include <iostream>
#include <thread>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>

#include "tr_parameter_init.hpp"
#include "../message_send.hpp"
#include "g_variable.hpp"
#include "update_tracked.hpp"
#include "false_position_tracking.hpp"
#include "interpolation_lost.hpp"

using namespace std;
using namespace cv;

#ifndef _FRAME_TRACKING_
#define _FRAME_TRACKING_

int frame_tracking();

#endif