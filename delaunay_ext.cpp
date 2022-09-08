#include "delaunay_ext.h"

E_locate CB_CD_AD_AB_maper(EdgeID e,int l){
    Point2f org,dst;
    int organs = sub_div.Subdiv2D::edgeOrg(e,&org);
    int dstans = sub_div.Subdiv2D::edgeDst(e,&dst);
    if(org.x<=dst.x){
        if(org.y<=dst.y){
            switch(l){
                case RIGHT:return E_locate::e_CB;
                case UP:return E_locate::e_CD;
                case LEFT:return E_locate::e_AD;
                case DOWN:return E_locate::e_AB;
                default:cout << "wrong locate" << endl;exit(4);
            }
        }
        else{
            switch(l){
                case RIGHT:return E_locate::e_CD;
                case UP:return E_locate::e_AD;
                case LEFT:return E_locate::e_AB;
                case DOWN:return E_locate::e_CB;
                default:cout << "wrong locate" << endl;exit(4); 
            }
        }
    }
    else{
        if(org.y<=dst.y){
            switch(l){
                case RIGHT:return E_locate::e_AB;
                case UP:return E_locate::e_CB;
                case LEFT:return E_locate::e_CD;
                case DOWN:return E_locate::e_AD;
                default:cout << "wrong locate" << endl;exit(4);
            }
        }
        else{
            switch(l){
                case RIGHT:return E_locate::e_AD;
                case UP:return E_locate::e_AB;
                case LEFT:return E_locate::e_CB;
                case DOWN:return E_locate::e_CD;
                default:cout << "wrong locate" << endl;exit(4);
            }
        }
    }
    return E_locate::e_AC;
}


EdgeID getNextEdgeID(EdgeID e,E_locate nx){
    EdgeID ans_id;
    switch(nx){
        case E_locate::e_AB:{
            ans_id = sub_div.Subdiv2D::getEdge(e,Subdiv2D::NEXT_AROUND_DST);
            return ans_id;
        }
        case E_locate::e_AD:{
            ans_id = sub_div.Subdiv2D::getEdge(e,Subdiv2D::NEXT_AROUND_RIGHT);
            return ans_id;
        }
        case E_locate::e_CB:{
            ans_id = sub_div.Subdiv2D::getEdge(e,Subdiv2D::PREV_AROUND_DST);
            return ans_id;
        }
        case E_locate::e_CD:{
            ans_id = sub_div.Subdiv2D::getEdge(e,Subdiv2D::PREV_AROUND_LEFT);
            return ans_id;
        }
        case E_locate::e_DB:{
            return e;
        }
        case E_locate::e_AC:{
            ans_id = sub_div.Subdiv2D::rotateEdge(e,1);
            return ans_id;
        }
        default:cout << "wrong nx" << endl;exit(5);
    }
    return ans_id;
}


Edge getNextEdge(EdgeID e,E_locate nx){
    EdgeID e_l_id= getNextEdgeID(e,nx);
    Point2f org,dst;
    int organs = sub_div.Subdiv2D::edgeOrg(e_l_id,&org);
    int dstans = sub_div.Subdiv2D::edgeDst(e_l_id,&dst);
    return Edge(org.x,org.y,dst.x,dst.y);
}


int condition_Judger(EdgeID e){
    Edge AB = getNextEdge(e,E_locate::e_AB);
    Edge AD = getNextEdge(e,E_locate::e_AD);
    Edge CB = getNextEdge(e,E_locate::e_CB);
    Edge CD = getNextEdge(e,E_locate::e_CD);
    int ans = 0;
    // cout << mod_multi(AD,CB) << endl;
    if(1-pow(mod_multi(AB,CD),2)<SP.thet_par
      &&1-pow(mod_multi(AD,CB),2)<SP.thet_par){
        ans|=1;
    }
    if(pow(mod_multi(AD,CD),2)<SP.thet_ver
        &&1-pow(mod_multi(AB,CB),2)<SP.thet_par){
            ans|=2;
    }
    return ans;
}

EdgeID get_eBar(EdgeID e,int locate){
    E_locate ans_locate = CB_CD_AD_AB_maper(e,locate);
    switch(ans_locate){
        case E_locate::e_CB: case E_locate::e_CD:
        {
            Edge DB = getNextEdge(e,E_locate::e_DB);
            Edge CB = getNextEdge(e,E_locate::e_CB);
            Edge CD = getNextEdge(e,E_locate::e_CD);
            float mod_cos_CB_DB = abs(mod_multi(CB,DB));
            float mod_cos_CD_DB = abs(mod_multi(CD,DB));
            if(mod_cos_CB_DB < mod_cos_CD_DB){
                return getNextEdgeID(e,E_locate::e_CD);
            }
            else{
                return getNextEdgeID(e,E_locate::e_CB);
            }
        }break;
        case E_locate::e_AB: case E_locate::e_AD:
        {
            Edge AB = getNextEdge(e,E_locate::e_AB);
            Edge AD = getNextEdge(e,E_locate::e_AD);
            Edge DB = getNextEdge(e,E_locate::e_DB);
            float mod_cos_AB_DB = abs(mod_multi(AB,DB));
            float mod_cos_AD_DB = abs(mod_multi(AD,DB));
            if(mod_cos_AB_DB < mod_cos_AD_DB){
                return getNextEdgeID(e,E_locate::e_AD);
            }
            else{
                return getNextEdgeID(e,E_locate::e_AB);
            }
        }break;
        default:{
            cout << "wrong locate num" << endl;
            exit(3);
        }
    }
    return -1;
}

