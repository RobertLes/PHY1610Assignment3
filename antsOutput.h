//antsUpdate.h

#ifndef ANTSOUTPUT_H
#define ANTSOUTPUT_H

//driver holds all required includes
#include "antsDriver.h"

//function to caluclate and print out the number of ants on the table
void outputPerStep(int t, int table_dim_x, int table_dim_y, rarray<float,2> number_of_ants);

#endif
