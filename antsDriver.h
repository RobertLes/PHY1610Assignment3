//antsDriver.h

#ifndef ANTSDRIVER_H
#define ANTSDRIVER_H

//M_PI not defined in c++11 standard?
#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

//all includes required by modules
#include <cmath>
#include <rarray>
#include <iostream>
#include "ticktock.h"

//include other modules of program
#include "antsOutput.h"
#include "antsInit.h"
#include "antsUpdate.h"

#endif
