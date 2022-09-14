#include <thread>
#include "pointid/pointid.hpp"
#include "frame_tracking/frame_tracking.hpp"

using namespace std;

int main(){
    thread point_id_thread(pointid),frame_tracking_thread(frame_tracking);
    point_id_thread.join();
    frame_tracking_thread.join();
    //系统等待
    this_thread::sleep_for(chrono::duration<double>(100000));
    return 0;
};