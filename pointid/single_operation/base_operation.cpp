#include "base_operation.hpp"

bool comp(const SN sn_1,const SN sn_2){
    if(sn_1.second>sn_2.second)return true;
    else return false;
}


float getDis_p2p(Point A,Point B){
    return sqrt(pow((A.x-B.x),2)+pow((A.y-B.y),2));
}


void paint_line(Edge l){
    Point p1(l[0],l[1]),p2(l[2],l[3]);
    line(redraw,p1,p2,Scalar(0,255,0));
}


float mod_multi(Edge n1,Edge n2){
    float mod1 = sqrt(pow(n1[3]-n1[1],2)+pow(n1[2]-n1[0],2));
    float mod2 = sqrt(pow(n2[3]-n2[1],2)+pow(n2[2]-n2[0],2));
    float multi = (n1[3]-n1[1])*(n2[3]-n2[1])+(n1[2]-n1[0])*(n2[2]-n2[0]);
    return multi/(mod1*mod2);
}

float mod_multi(EdgeID e1,EdgeID e2){
    Point2f p01,p02,p11,p12;
    sub_div.Subdiv2D::edgeOrg(e1,&p01);
    sub_div.Subdiv2D::edgeDst(e1,&p02);
    Edge n1 = Edge(p01.x,p01.y,p02.x,p02.y);
    sub_div.Subdiv2D::edgeOrg(e2,&p11);
    sub_div.Subdiv2D::edgeDst(e2,&p12);
    Edge n2 = Edge(p11.x,p11.y,p12.x,p12.y);
    return mod_multi(n1,n2);
}

void cout_paint_line(string s,EdgeID e){
    Point2f org,dst;
    int organs = sub_div.Subdiv2D::edgeOrg(e,&org);
    int dstans = sub_div.Subdiv2D::edgeDst(e,&dst);
    line(redraw,org,dst,Scalar(0,255,0));
    cout << s <<":["<<org<<","<<dst<<"]"<<endl;
}

int** reset_matrix(Point origin,int** matrix,int x_side,int y_side){
    int** ans_matrix = new int*[x_side];
    for(int x=0;x<x_side;x++){
        ans_matrix[x] = new int[y_side];
        for(int y=0;y<y_side;y++){
            int _x = x-origin.x>=0?x-origin.x:x+x_side-origin.x;
            int _y = y-origin.y>=0?y-origin.y:y+y_side-origin.y;
            ans_matrix[_x][_y] = matrix[x][y];
        }
    }
    return ans_matrix;
}