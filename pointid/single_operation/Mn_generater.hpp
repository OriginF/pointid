#include "../def.hpp"
#include "../g_variable.hpp"
#include "delaunay_ext.hpp"
#include "L_sq_se_calculator.hpp"
#include "negMatrix.hpp"

#ifndef _NAME_MN_
#define _NAME_MN_

//边的合法性检查
bool e_legal(EdgeID e_id);

//计算Mn
void getMn(NegMatrix<int>* Mn,vector<SN> Sn);

#endif