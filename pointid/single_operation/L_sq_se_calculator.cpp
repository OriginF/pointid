#include "L_sq_se_calculator.hpp"

float L_sq_se_calculator(EdgeID e){
    Point2f p1,p2;
    EdgeID AB_id = sub_div->Subdiv2D::getEdge(e,Subdiv2D::NEXT_AROUND_DST);
    sub_div->Subdiv2D::edgeOrg(AB_id,&p1);
    sub_div->Subdiv2D::edgeDst(AB_id,&p2);
    Edge AB(p1.x,p1.y,p2.x,p2.y);
    EdgeID AD_id = sub_div->Subdiv2D::getEdge(e,Subdiv2D::NEXT_AROUND_RIGHT);
    sub_div->Subdiv2D::edgeOrg(AD_id,&p1);
    sub_div->Subdiv2D::edgeDst(AD_id,&p2);
    Edge AD(p1.x,p1.y,p2.x,p2.y);
    EdgeID CB_id = sub_div->Subdiv2D::getEdge(e,Subdiv2D::PREV_AROUND_DST);
    sub_div->Subdiv2D::edgeOrg(CB_id,&p1);
    sub_div->Subdiv2D::edgeDst(CB_id,&p2);
    Edge CB(p1.x,p1.y,p2.x,p2.y);
    EdgeID CD_id = sub_div->Subdiv2D::getEdge(e,Subdiv2D::PREV_AROUND_LEFT);
    sub_div->Subdiv2D::edgeOrg(CD_id,&p1);
    sub_div->Subdiv2D::edgeDst(CD_id,&p2);
    Edge CD(p1.x,p1.y,p2.x,p2.y);
    Edge AC(AB[0],AB[1],CB[0],CB[1]);
    Edge DB(CD[2],CD[3],CB[2],CB[3]);
    float Lsq_se=1.0
        -1.0/3.0*pow(mod_multi(AB,AD),2)
        -1.0/3.0*pow(mod_multi(CB,CD),2)
        -1.0/3.0*pow(mod_multi(AC,DB),2);
    return Lsq_se;
}