#include "../def.hpp"
#include "../g_variable.hpp"
#include "delaunay_ext.hpp"
#include "L_sq_se_calculator.hpp"
#include "negMatrix.hpp"

#ifndef _NAME_MN_
#define _NAME_MN_

//计算Mn
void getMn(NegMatrix<int>* Mn,vector<SN> Sn);

#endif