
#ifndef _FRAME_TRACKING_GLOBAL_VAR_
#define _FRAME_TRACKING_GLOBAL_VAR_

//表示ROI窗口的大小，原文中设计成了有关t的函数，但是我先设计成常数，后续如果需要我再进行修正
//有点比较奇怪的事情就是目前已经将所有的点簇都抽离出来了，但是这里又做了一次点簇的抽离算法。
extern int W_ROI;

#endif