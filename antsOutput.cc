//antsOutput.cc

//include header
#include "antsOutput.h"

//function to caluclate and output number of ants on table
void outputPerStep(int t, int table_dim_x, int table_dim_y, rarray<float,2> number_of_ants){
    
    //start with 0
    float totants = 0.0;
      
    //count total number of ants
    for (int i=0;i<table_dim_x;i++) {
        for (int j=0;j<table_dim_y;j++) {
            totants += number_of_ants[i][j];
        }
    }

    //output results
    std::cout << t<< " " << totants << std::endl;
}
