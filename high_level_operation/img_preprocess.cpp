#include "../g_variable.hpp"

vector<Point> get_points(int nccpmps,Mat stats,Mat centroids){
    vector<Point> connect_points;
    for(int i=1;i<nccpmps;i++){
        if(stats.at<int>(i,CC_STAT_AREA)>SP.Amin&&stats.at<int>(i,CC_STAT_AREA)<SP.Amax){
            connect_points.push_back(Point(centroids.at<Vec2d>(i,0)));
        }
    }
    return connect_points;
}