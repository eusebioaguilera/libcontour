#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Suites
#include <boost/test/unit_test.hpp>
#include <evaluator.hpp>
#include <contour.hpp>
#include <point.hpp>

BOOST_AUTO_TEST_SUITE(Evaluator)
BOOST_AUTO_TEST_CASE(constructors)
{
	// Read contour from file
	libcontour::Contour c = libcontour::Contour( "../figures/cromosoma.txt" );
	
	c.markAsDominant( 0 );
	c.markAsDominant( 10 );
	c.markAsDominant( 20 );
	
	libcontour::Evaluator eval = libcontour::Evaluator( c );
}

BOOST_AUTO_TEST_CASE(ise)
{
	// Read contour from file
	libcontour::Contour c = libcontour::Contour( "../figures/cromosoma.txt" );
	
	
	int dominants[] = { 1, 10, 14, 16, 22, 27, 29, 31, 33, 37, 43, 46, 48, 50 ,53 ,55, 59 };
	
	double wu_ise = 5.01; // This value appear in Pattern Recognition 36 (2003) 2231 – 2237
	
	int size = sizeof( dominants ) / sizeof( int );
	
	for ( int i = 0; i < size; i++ ) {
		c.markAsDominant( dominants[ i ] );
	}
	
	libcontour::Evaluator eval = libcontour::Evaluator( c );
	
	//std::cout << eval.ise() << std::endl;
	
	BOOST_CHECK( ( eval.ise() - wu_ise ) < 0.05 );

}

BOOST_AUTO_TEST_SUITE_END()
