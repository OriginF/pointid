#include "Mn_generater.h"

void getMn(NegMatrix<int>* Mn,vector<SN> Sn){
    for(int i=0;i<Sn.size();i++){//这里的这个Mn的大小实际上是需要我们进行一个优化，但是我还没有考虑好空间的上界，目前先设立成这个大小。
        Mn[i].reset(SP.cluster_side,SP.cluster_side,-1);
    }
    vector<bool> Sn_mark(SP.max_edge_id,false);//这里感觉还是有一点奇怪的，因为此处实际上是开始只设立一个mark，但是要重复对每个点进行一次考虑。
    for(int n=0;n<Sn.size();n++){
        if(!Sn_mark[Sn[n].first]){
            Sn_mark[Sn[n].first] = true;
            Mn[n].set(0,0,Sn[n].first);
            queue<pair<EdgeID,Point>> Q;
            Q.push(pair<EdgeID,Point>(Sn[n].first,Point(0,0)));
            int counter = 0;
            while(!Q.empty()){
                counter++;
                EdgeID id = Q.front().first;
                Point p = Q.front().second;
                Q.pop();
                for(int l=0;l<=3;l++){
                    E_locate l_locate = CB_CD_AD_AB_maper(id,l);
                    EdgeID e_id = getNextEdgeID(id,l_locate);
                    Point2f p01,p02;
                    int ans1 = sub_div.Subdiv2D::edgeDst(e_id,&p01);
                    int ans2 = sub_div.Subdiv2D::edgeOrg(e_id,&p02);
                    int condition_ans = condition_Judger(e_id);
                    if(condition_ans>0){//这个地方变成的可能不是原来的那个边，很奇怪（有可能覆盖原来的位置
                        EdgeID eBar_id = get_eBar(e_id,l);
                        Point eBar_p;
                        int eBar_condition_ans = condition_Judger(eBar_id);
                        float cos = abs(mod_multi(id,eBar_id));
                        if(cos>0.80&&cos<1-1e-3){continue;};//这个地方很奇怪，在所有的情况下，cos都应该小于1
                        if(!Sn_mark[eBar_id]&&((eBar_condition_ans&1)>0)){//现在每种情况下，这里只会在单个地方进行访问？
                            switch(l){
                                case 0:
                                    eBar_p = Point(p.x,p.y+1);
                                    // if(p.y+1>=SP.cluster_side)continue;
                                    Mn[n].set(p.x,p.y+1,eBar_id);
                                    break;
                                case 1:
                                    eBar_p = Point(p.x-1,p.y);
                                    // if(p.x-1<0)continue;
                                    Mn[n].set(p.x-1,p.y,eBar_id);
                                    break;
                                case 2:
                                    eBar_p = Point(p.x,p.y-1);
                                    // if(p.y-1<0)continue;
                                    Mn[n].set(p.x,p.y-1,eBar_id);
                                    break;
                                case 3:
                                    eBar_p = Point(p.x+1,p.y);
                                    // if(p.x+1>=SP.cluster_side)continue;
                                    Mn[n].set(p.x+1,p.y,eBar_id);
                                    break;
                                default:
                                    cout << "wrong l num"<< endl;
                                    exit(-2);
                            }
                            Point2f p1,p2;
                            int ans1 = sub_div.Subdiv2D::edgeDst(eBar_id,&p1);
                            int ans2 = sub_div.Subdiv2D::edgeOrg(eBar_id,&p2);
                            // if(n==0)line(redraw,p1,p2,Scalar(255,0,100));
                            // if(n==0)cout << eBar_p << endl;
                            Q.push(pair<EdgeID,Point>(eBar_id,eBar_p));
                            Sn_mark[eBar_id] = true;
                            EdgeID rotate_eBar_id = sub_div.Subdiv2D::rotateEdge(eBar_id,2);
                            Sn_mark[rotate_eBar_id] = true;
                        }
                    }
                }
            }
        }
    }
}