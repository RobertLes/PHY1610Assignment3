#include <rarray>
#define BOOST_TEST_MODULE myTest
#include <boost/test/included/unit_test.hpp>

int add(int i, int j) {return i+j;}

rarray<float,2> findNewArray(int table_dim_x, int table_dim_y,rarray<float,2> number_of_ants,rarray<float,2> velocity_of_ants){
	
	//define array to be filled with updated values
	rarray<float,2> new_number_of_ants(table_dim_x,table_dim_y);
	new_number_of_ants.fill(0);

	//loop over table
        for (int i=0;i<table_dim_x;i++) {
            for (int j=0;j<table_dim_y;j++) {
                
                //find new postions of ants
		int di = 1.9*sin(velocity_of_ants[i][j]);
                int dj = 1.9*cos(velocity_of_ants[i][j]);
                int i2 = i + di;
                int j2 = j + dj;
                
		// some ants do not walk
                new_number_of_ants[i][j]+=0.8*number_of_ants[i][j];
                
		// the rest of the ants walk, but some fall of the table
                if (i2>=0 and i2<table_dim_x and j2>=0 and j2<table_dim_y) {
                    new_number_of_ants[i2][j2]+=0.2*number_of_ants[i][j];
                }
            }
        }
 
    //return new array	
    return new_number_of_ants;
}


BOOST_AUTO_TEST_SUITE(my_test)
BOOST_AUTO_TEST_CASE(my_test)
{	
	int dim=10;
	rarray<float,2> ants(dim,dim);
	rarray<float,2> velocity(dim,dim);
	
	ants.fill(1);
	velocity.fill(1);

	rarray<float,2> updated=ants.copy();
	updated=findNewArray(dim,dim,ants,velocity);

	float originalCounter=0;
	float updatedCounter=0;

	for(int i=0;i<dim;i++){
	    for(int j=0;j<dim;j++){
		originalCounter+=ants[i][j];
		updatedCounter+=updated[i][j];
            }
        }
	
	BOOST_CHECK(originalCounter>updatedCounter);
}
BOOST_AUTO_TEST_SUITE_END ()
