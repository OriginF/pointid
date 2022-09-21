#include <iostream>
#include <thread>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/imgproc/imgproc.hpp>
#include "opencv2/core/core.hpp"

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

void frame_tracking_run();

int frame_tracking(VideoWriter writer);

#endif