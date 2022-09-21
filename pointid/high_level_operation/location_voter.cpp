#include "location_voter.hpp"

int vote_num(Point init_p,Point id_p,int** cluster_location,bool** read_mark){
    if(id_p.x>=SP.cluster_side||id_p.y>=SP.cluster_side||id_p.x<0||id_p.y<0){return 0;}
    if(read_mark[id_p.x][id_p.y]){return 0;}
    if(cluster_location[id_p.x][id_p.y]==-1){return 0;}
    if(init_p.x>=PAPER_SIDE||init_p.y>=PAPER_SIDE||init_p.x<0||init_p.y<0){return 0;}
    int votes = 0;
    if(init_cluster_num[init_p.x][init_p.y]==cluster_location[id_p.x][id_p.y]){
        votes++;
    }
    read_mark[id_p.x][id_p.y] = true;
    votes+=vote_num(Point(init_p.x+1,init_p.y),Point(id_p.x+1,id_p.y),cluster_location,read_mark);
    votes+=vote_num(Point(init_p.x,init_p.y+1),Point(id_p.x,id_p.y+1),cluster_location,read_mark);
    votes+=vote_num(Point(init_p.x-1,init_p.y),Point(id_p.x-1,id_p.y),cluster_location,read_mark);
    votes+=vote_num(Point(init_p.x,init_p.y-1),Point(id_p.x,id_p.y-1),cluster_location,read_mark);
    return votes;
}

void init_marks(bool** read_mark){
    for(int i=0;i<SP.cluster_side;i++){
        for(int j=0;j<SP.cluster_side;j++){
            read_mark[i][j] = false;
        }
    }
}

Point location_voter(int** identified_cluster_num){
    bool** read_mark = new bool*[SP.cluster_side];
    for(int i=0;i<SP.cluster_side;i++){
        read_mark[i] = new bool[SP.cluster_side];
        for(int j=0;j<SP.cluster_side;j++){
            read_mark[i][j] = false;
        }
    }
    Point ans(0,0);
    switch(identified_cluster_num[0][0]){
        case 1:{
            int max_index = 0;
            int max_votes = 0;
            for(int i=0;i<_1_NUM_;i++){
                int votes = vote_num(L_1[i],Point(0,0),identified_cluster_num,read_mark);
                if(votes>max_votes){max_votes = votes;max_index = i;}
                init_marks(read_mark);
            }
            ans = L_1[max_index];
        }break;
        case 2:{
            int max_index = 0;
            int max_votes = 0;
            for(int i=0;i<_2_NUM_;i++){
                int votes = vote_num(L_2[i],Point(0,0),identified_cluster_num,read_mark);
                if(votes>max_votes){max_votes = votes;max_index = i;}
                init_marks(read_mark);
            }
            ans = L_2[max_index];
        }break;
        case 3:{
            int max_index = 0;
            int max_votes = 0;
            for(int i=0;i<_3_NUM_;i++){
                int votes = vote_num(L_3[i],Point(0,0),identified_cluster_num,read_mark);
                if(votes>max_votes){max_votes = votes;max_index = i;}
                init_marks(read_mark);
            }
            ans = L_3[max_index];
        }break;
        case 4:{
            int max_index = 0;
            int max_votes = 0;
            for(int i=0;i<_4_NUM_;i++){
                int votes = vote_num(L_4[i],Point(0,0),identified_cluster_num,read_mark);
                if(votes>max_votes){max_votes = votes;max_index = i;}
                init_marks(read_mark);
            }
            ans = L_4[max_index];
        }break;
    }
    for(int i=0;i<SP.cluster_side;i++){
        delete[] read_mark[i];
    }
    delete[] read_mark;
    return ans;
}
