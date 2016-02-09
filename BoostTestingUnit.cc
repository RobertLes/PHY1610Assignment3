#define BOOST_TEST_MODULE myTest
#include <boost/test/included/unit_test.hpp>
#include "antsUpdate.h"
#include <rarray>

BOOST_AUTO_TEST_SUITE(test_update)
BOOST_AUTO_TEST_CASE(test_total_number_decreases)
{	
	//make a table of ant and velocities
	int dim=10;
	rarray<float,2> ants(dim,dim);
	rarray<float,2> velocity(dim,dim);
	
	//fill rarrays with a number
	ants.fill(1);
	velocity.fill(.5);
	
	//make a copy or original array and update it with function to be tested
	rarray<float,2> updated=ants.copy();
	updated=findNewArray(dim,dim,ants,velocity);

	float originalCounter=0;
	float updatedCounter=0;

	//count the number of ants in original and updated rarrays
	for(int i=0;i<dim;i++){
	    for(int j=0;j<dim;j++){
		originalCounter+=ants[i][j];
		updatedCounter+=updated[i][j];
            }
        }
	
	//check that counter goes down, ie that ants fall off table
	BOOST_CHECK(originalCounter>updatedCounter);
}
BOOST_AUTO_TEST_SUITE_END ()
