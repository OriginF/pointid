#include "../def.hpp"
#include "../g_variable.hpp"

#ifndef _LOCATION_VOTER_
#define _LOCATION_VOTER_

int vote_num(Point init_p,Point id_p,int** cluster_location,bool** read_mark);


void init_marks(bool** read_mark);


Point location_voter(int** identified_cluster_num);

#endif