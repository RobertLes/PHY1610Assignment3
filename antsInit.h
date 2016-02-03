//antsInit.h

#ifndef ANTSINIT_H
#define ANTSINIT_H

//driver header has all required includes
#include "antsDriver.h"

//function to intiate velocity_of_ants array with intial values
void initVel(int table_dim_x, int table_dim_y, rarray<float,2> velocity_of_ants);

//function to initate number_of_ants array with intial values
void initAnts(int table_dim_x, int table_dim_y, const int total_ants,rarray<float,2> number_of_ants);

#endif
