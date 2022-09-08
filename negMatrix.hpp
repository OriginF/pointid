#include <vector>
#include <iostream>
using namespace std;

template<class T>
class NegMatrix{
public:
    int x_side;
    int y_side;
    int x_bias;
    int y_bias;
    int x_max;
    int y_max;
    T **matrix;
public:
    void reset(int x_side_,int y_side_,T value){
        x_side = x_side_;
        y_side = y_side_;
        x_bias = y_bias = x_max = y_max = 0;
        matrix = new T*[x_side];
        for(int i=0;i<x_side;i++){
            matrix[i] = new T[y_side];
            for(int j=0;j<y_side;j++){
                matrix[i][j] = -1;
            }
        }
    }
    bool set(int x,int y,T value){
        if(x_max-x>=x_side||y_max-y>=y_side)return false;
        if(x<x_bias)x_bias = x;
        if(y<y_bias)y_bias = y;
        if(x>x_max)x_max = x;
        if(y>y_max)y_max = y;
        x = x<0?x_side+x:x;
        y = y<0?y_side+y:y;
        matrix[x][y]=value;
    }
    T get(int x,int y){
        if(x<x_bias||y<y_bias||x>=x_max||y>=y_max){
            cout << "wrong matrix locate" << endl;
            exit(6);
        }
        x = x<0?x_side+x:x;
        y = y<0?y_side+y:y;
        return matrix[x][y];
    }

    T get_normal(int x,int y){
        if(x>=x_side||y>=y_side){
            cout << "wrong normal locate" << endl;
            exit(6);
        }
        return matrix[x][y];
    }
};