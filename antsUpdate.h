//antsUpdate.h

#ifndef ANTSUPDATE_H
#define ANTSUPDATE_H

//driver header has all required headers
#include "antsDriver.h"

//array to caluclate the new table of ants array at each step given old array
rarray<float,2> findNewArray(int table_dim_x, int table_dim_y,rarray<float,2> number_of_ants,rarray<float,2> velocity_of_ants);

#endif
