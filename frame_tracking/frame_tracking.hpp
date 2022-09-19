#include <iostream>
#include <thread>

#include "tr_parameter_init.hpp"
#include "../message_send.hpp"
#include "g_variable.hpp"
#include "update_tracked.hpp"
#include "false_position_tracking.hpp"

using namespace std;

#ifndef _FRAME_TRACKING_
#define _FRAME_TRACKING_

int frame_tracking();

#endif