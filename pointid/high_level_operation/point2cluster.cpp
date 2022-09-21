#include "point2cluster.hpp"

void point2cluster(vector<Point> connect_points){
    //添加网格分割
    redraw=Mat(SP.row,SP.col,CV_8UC3,Scalar(255,255,255));
    int row_num = SP.row/SP.div;
    int col_num = SP.col/SP.div;
    for(int i=0;i<=row_num;i++){
        line(redraw,Point(0,i*SP.div),Point(SP.col,i*SP.div),Scalar(0,0,0));
    }
    for(int i=0;i<=col_num;i++){
        line(redraw,Point(i*SP.div,0),Point(i*SP.div,SP.row),Scalar(0,0,0));
    }

     //点簇分割,这个原来的论文里面没有讲,但是我觉得可以加上,效果会更好,可以省去大量的计算
    vector<int> cluster_counter;
    vector<Point> cluster_center;
    vector<int> point2cluster;
    for(int i=0;i<connect_points.size();i++){
        bool new_cluster=true;
        for(int j=0;j<i;j++){
            if(getDis_p2p(connect_points[i],connect_points[j])<SP.d_cl){
                point2cluster.push_back(point2cluster[j]);
                cluster_counter[point2cluster[j]]++;
                cluster_center[point2cluster[j]].x+=connect_points[i].x;
                cluster_center[point2cluster[j]].y+=connect_points[i].y;
                new_cluster = false;
                break;
            }
        }
        if(new_cluster){
            cluster_counter.push_back(1);
            cluster_center.push_back(Point(connect_points[i]));
            point2cluster.push_back(cluster_counter.size()-1);
        }
    }
    for(int i=0;i<cluster_center.size();i++){
        cluster_center[i].x/=cluster_counter[i];
        cluster_center[i].y/=cluster_counter[i];
    }
    assert(point2cluster.size()==connect_points.size());
    
    
    //这里已经拿到了所有的cluster，现在尝试对cluster进行分割
    //开始遍历点和网格分割(这没想好,但是感觉复杂度挺高的,O(n^2*m),n表示点的个数,m表示方格的个数),删除方格内超过16个的点的方格
    vector<int>** grid_queue = new vector<int>*[row_num+1];
    for(int i=0;i<=row_num;i++){
        grid_queue[i] = new vector<int>[col_num+1];
    }
    for(int point=0;point<connect_points.size();point++){
        Point p(connect_points[point]);
        for(float i=0;i<=row_num;i++){
            if(p.x>=i*SP.div&&p.x<=(i+1)*SP.div){
                for(float j=0;j<=col_num;j++){
                    if(p.y>=j*SP.div&&p.y<=(j+1)*SP.div){
                        grid_queue[int(i)][int(j)].push_back(point);
                    }
                }
            }
        }
    }
    

    vector<Point> grid_points;
    vector<int> point_id;
    vector<Point> temp_clusters;
    vector<int> temp_counter;
    for(float i=0;i<=row_num;i++){
        for(float j=0;j<=col_num;j++){
            vector<int> grid_q = grid_queue[int(i)][int(j)];
            set<int> cl_set;
            for(int point=0;point<grid_q.size();point++){
                cl_set.insert(point2cluster[grid_q[point]]);
            }
            if(grid_q.size()<=cl_set.size()*4){
                for(int q:grid_q){
                    grid_points.push_back(connect_points[q]);
                    point_id.push_back(q);
                }
            }
        }
    }
    for(int i=0;i<point_id.size();i++){
        Point center = cluster_center[point2cluster[point_id[i]]];
        int counter = cluster_counter[point2cluster[point_id[i]]];
        temp_clusters.push_back(center);
        temp_counter.push_back(counter);
    }


    for(int i=0;i<temp_clusters.size();i++){
        bool new_point=true;
        if(temp_counter[i]>4)continue;
        for(int j=0;j<i;j++){
            if(temp_clusters[i]==temp_clusters[j]){
                new_point= false;
                break;
            }
        }
        if(new_point){
            clusters.push_back(temp_clusters[i]);
            cluster_size.push_back(temp_counter[i]);
        }
    }

    //单个点簇不能太大（目前还没加这个优化，可能到后面就加上，应该会有效果
    // vector<Point> cluster_points;
    // for(int i=0;i<grid_points.size();i++){
    //     if(cluster_counter[point2cluster[i]]<=SP.n_cl){
    //         cluster_points.push_back(connect_points[i]);
    //     }
    // }

    //最后绘制一下所有的点簇的点，用来比较
    for(Point p:grid_points){
        circle(redraw,p,3,Scalar(0,0,0),1,LINE_8,0);
    }
    for(int i=0;i<row_num;i++){
        delete[] grid_queue[i];
    }
    delete[] grid_queue;
    return;
}
