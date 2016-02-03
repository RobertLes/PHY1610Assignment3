#include "antsUpdate.h"

#define BOOST_TEST_MODULE myTest
#include <boost/test/included/unit_test.hpp>
int add(int i, int j) {return i+j;}
//BOOST_AUTO_TEST_SUITE(my_test)
BOOST_AUTO_TEST_CASE(my_test)
{
	BOOST_CHECK(add(2,2)==4);
}
//BOOST_AUTO_TEST_SUITE_END ()
