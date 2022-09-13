#include "../g_variable.hpp"

void parameter_init(){

    //对对照图片进行预设参数
    SP_0.row = 1374.0;
    SP_0.col = 882.0;
    SP_0.Amax = 80.0;
    SP_0.Amin = 7.0;
    SP_0.div = 111.3;//以此为分割长度,一个里面至多有4个点簇
    SP_0.d_cl = 20;//以此为点簇判定标准,一个点簇至多有四个点
    SP_0.resolution = 1374.0*882.0;
    SP_0.LSE = 0.1;//LSE threshold
    SP_0.thet_par = 0.55;
    SP_0.thet_ver = 0.55;
    SP_0.cluster_side = 10;

    SP.url = "./realimage/real2.jpg";
    // SP.url = "./points.jpg";


    //预处理全局变量
    LOCATE[0] = E_locate::e_CB;
    LOCATE[1] = E_locate::e_CD;
    LOCATE[2] = E_locate::e_AD;
    LOCATE[3] = E_locate::e_AB;
    LOCATE[4] = E_locate::e_AC;
    LOCATE[5] = E_locate::e_DB;
}

void parameter_convert(Mat src){
    SP.row = src.rows;
    SP.col = src.cols;
    SP.resolution = src.rows*src.cols;
    SP.Amax = sqrt(SP.resolution/SP_0.resolution)*SP_0.Amax;
    SP.Amin = sqrt(SP.resolution/SP_0.resolution)*SP_0.Amin;
    SP.div = sqrt(SP.resolution/SP_0.resolution)*SP_0.div;
    SP.d_cl = sqrt(SP.resolution/SP_0.resolution)*SP_0.d_cl;
    SP.n_kp = 16;
    SP.n_cl = 4;
    SP.LSE = SP_0.LSE;
    SP.thet_par = SP_0.thet_par;
    SP.thet_ver = SP_0.thet_ver;
    SP.cluster_side = SP_0.cluster_side;
}