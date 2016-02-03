//antsDriver.cc

//include header
#include "antsDriver.h"

//start code
int main()
{
    TickTock stopwatch1;
    TickTock stopwatch2;

    stopwatch1.tick();
    //size of table
    int table_dim_x = 356;
    int table_dim_y = 356;

    // ants walk on a table
    rarray<float,2> number_of_ants(table_dim_x,table_dim_y);
    rarray<float,2> velocity_of_ants(table_dim_x,table_dim_y);

    //intial number of ants
    const int total_ants = 1010;
    
    //intialize arrays, use functions from antsInit
    initAnts(table_dim_x,table_dim_y, total_ants,number_of_ants);
    initVel(table_dim_x,table_dim_y,velocity_of_ants);

    double initTime=stopwatch2.silent_tock();

    double updateTime=-1.0;
    
    stopwatch1.tick();
    // run simulation
    for (int t = 0; t < 40; t++) {
	//print out total number of ants, use functions from antsOutput
	outputPerStep(t,table_dim_x,table_dim_y,number_of_ants);
     	
	if(t==0)
             stopwatch2.tick();
      	
	//update the number of ants array, use function from antsUpdate	
	number_of_ants=findNewArray(table_dim_x,table_dim_y,number_of_ants,velocity_of_ants);
    	if(t==0)
	     updateTime= stopwatch2.silent_tock();
    	
    }
    double loopTime = stopwatch1.silent_tock();

    std::cout<< "Timing Results" <<std::endl;
    std::cout<< "Time to Initialize array:\t"<< initTime <<std::endl;
    std::cout<< "Time to do first update:\t"<<updateTime<<std::endl;
    std::cout<< "Time to finish all looping:\t"<<loopTime<<std::endl;

    return 0;
}
