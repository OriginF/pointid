#include "../def.hpp"
#include "../g_variable.hpp"
#include "base_operation.hpp"

#ifndef _NAME_DELAUNAY_EXT_
#define _NAME_DELAUNAY_EXT_

//根据方位获得对应的边相对位置
E_locate CB_CD_AD_AB_maper(EdgeID e,int l);

//根据对应的边相对位置，获得对应的边的ID
EdgeID getNextEdgeID(EdgeID e,E_locate nx);

//根据对应的边相对位置，获得对应的边
Edge getNextEdge(EdgeID e,E_locate nx);

//计算对应的边，是否符合condition(i)和condition(ii)
int condition_Judger(EdgeID e);

//根据边e和方位获得对应的边eBar的id
EdgeID get_eBar(EdgeID e,int locate);

#endif
