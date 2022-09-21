#include "false_position_tracking.hpp"

float dBar_calculator(int& count, int i0,int j0,int i1,int j1){
    if(cluster_track[i1][j1]==S_TRACK::lost)return 0.0;
    float ans_x=0, ans_y=0;
    ans_x += (tracked_location[i0][j0].x - tracked_location[i1][j1].x);
    ans_y += (tracked_location[i0][j0].y - tracked_location[i1][j1].y);
    cout << ans_x << " " << ans_y << endl;
    float ans = sqrt(pow(ans_x,2)+pow(ans_y,2));
    count++;
    return ans;
}

void false_position_tracking(){
    float** d_average = new float*[g_side];
    int** N_1 = new int*[g_side];
    float d_sum = 0.0;
    int test_num = 0;
    for(int i=0;i<g_side;i++){
        d_average[i] = new float[g_side];
        N_1[i] = new int[g_side];
        for(int j=0;j<g_side;j++){
            if(cluster_track[i][j]==S_TRACK::lost)continue;
            d_average[i][j] = 0.0;
            N_1[i][j] = 0;
            if(i>0)d_average[i][j]+=dBar_calculator(N_1[i][j],i,j,i-1,j);
            if(i<g_side-1)d_average[i][j]+=dBar_calculator(N_1[i][j],i,j,i+1,j);
            if(j>0)d_average[i][j]+=dBar_calculator(N_1[i][j],i,j,i,j-1);
            if(j<g_side-1)d_average[i][j]+=dBar_calculator(N_1[i][j],i,j,i,j+1);
            d_sum += d_average[i][j];
            if(d_average[i][j]!=0)test_num++;
        }
    }
    d_sum /= test_num;
    for(int i=0;i<g_side;i++){
        for(int j=0;j<g_side;j++){
            float dBar = d_average[i][j]/(d_sum*float(N_1[i][j]));
            if(dBar>_D_BAR&&N_1[i][j]!=0){cluster_track[i][j] = S_TRACK::lost;};
        }
    }
    for(int i=0;i<g_side;i++){
        delete[] d_average[i];
        delete[] N_1[i];
    }
    delete[] d_average;
    delete[] N_1;
}