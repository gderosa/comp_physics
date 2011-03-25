#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE( test_suite_1 )

BOOST_AUTO_TEST_CASE( test_case_1 )
{
  int i;
  for (i=0; i<1000; i++)
    BOOST_CHECK_MESSAGE( i < 997, i << " is not > 997" );

     // BOOST_CHECK( false );
}

BOOST_AUTO_TEST_SUITE_END()

