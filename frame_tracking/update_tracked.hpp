#include "g_variable.hpp"


#ifndef _UPDATE_TRACKED_
#define _UPDATE_TRACKED_

void point_plus(Point2f& point,int& count,int i1,int j1,int i2,int j2);

Point2f location_estimate(int i,int j);

void update_tracked();

#endif