//include header
#include "antsInit.h"

//function to output intial array for velcoity_of_ants
void initVel(int table_dim_x, int table_dim_y,rarray<float,2> velocity_of_ants){
     
     //loop over and fill
     for (int i=0;i<table_dim_x;i++) {
       for (int j=0;j<table_dim_y;j++) {
          velocity_of_ants[i][j] = M_PI*(sin((2*M_PI*(i+j))/3560)+1);
      }
   }
}

//function to output intial array for number_of_ants
void initAnts(int table_dim_x, int table_dim_y, const int total_ants,rarray<float,2> number_of_ants){
    //counters
    int n = 0;
    float z = 0;
    
    //fill the number of ants array up to a certain total value
    while (n < total_ants) {
        for (int i=0;i<table_dim_x;i++) {
            for (int j=0;j<table_dim_y;j++) {
                z += sin(0.3*(i+j));
                if (z>1 and n!=total_ants) {
                    number_of_ants[i][j] += 1;
                    n += 1;
                }
             }
         }
    }
}
