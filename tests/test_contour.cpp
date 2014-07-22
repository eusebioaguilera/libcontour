#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Suites
#include <boost/test/unit_test.hpp>
#include <contour.hpp>
#include <point.hpp>

BOOST_AUTO_TEST_SUITE(Contour)
BOOST_AUTO_TEST_CASE(constructors)
{
	// Empty
	libcontour::Contour c1 = libcontour::Contour( );
	BOOST_CHECK_EQUAL(c1.size(), 0);
	
	// Read contour from file
	libcontour::Contour c2 = libcontour::Contour( "../figures/cromosoma.txt" );
	BOOST_CHECK_EQUAL(c2.size(), 60);
	
	// Copy constructor
	libcontour::Contour c3 = libcontour::Contour( c2.slice( 0, 59 ) );
	BOOST_CHECK_EQUAL(c3.size(), 60);
}

BOOST_AUTO_TEST_CASE(operatorAt)
{
	// Read contour from file
	libcontour::Contour c = libcontour::Contour( "../figures/cromosoma.txt" );
	
	BOOST_CHECK_EQUAL(c[0].x(), 0.0);
	BOOST_CHECK_EQUAL(c[0].y(), 0.0);
	
}

BOOST_AUTO_TEST_CASE(size)
{
	// Read contour from file
	libcontour::Contour c = libcontour::Contour( "../figures/cromosoma.txt" );
	
	BOOST_CHECK_EQUAL(c.size(), 60);
	
}

BOOST_AUTO_TEST_CASE(dominantSize)
{
	// Read contour from file
	libcontour::Contour c = libcontour::Contour( "../figures/cromosoma.txt" );
	
	c.dominant( 0, true );
	c.dominant( 1, true );
	
	BOOST_CHECK_EQUAL(c.dominantsSize(), 2);
	
}

//BOOST_AUTO_TEST_CASE(indexOf)
//{
	//// Read contour from file
	//libcontour::Contour c = libcontour::Contour( "../figures/cromosoma.txt" );
	
	//BOOST_CHECK_EQUAL(c.index_of( libcontour::Point(-1,1) ), 59);
	
//}

BOOST_AUTO_TEST_CASE(dominantNextNeighbour)
{
	// Read contour from file
	libcontour::Contour c = libcontour::Contour( "../figures/cromosoma.txt" );
	
	c.dominant(0, true);
	c.dominant(10, true);
	c.dominant(20, true);
	
	BOOST_CHECK_EQUAL(c.dominantNextNeighbour( 0 ), 10);
	BOOST_CHECK_EQUAL(c.dominantNextNeighbour( 10 ), 20);
	BOOST_CHECK_EQUAL(c.dominantNextNeighbour( 20 ), 0);
}

BOOST_AUTO_TEST_CASE(dominantPreviousNeighbour)
{
	// Read contour from file
	libcontour::Contour c = libcontour::Contour( "../figures/cromosoma.txt" );
	
	c.dominant(0, true);
	c.dominant(10, true);
	c.dominant(20, true);
	
	BOOST_CHECK_EQUAL(c.dominantPreviousNeighbour( 0 ), 20);
	BOOST_CHECK_EQUAL(c.dominantPreviousNeighbour( 10 ), 0);
	BOOST_CHECK_EQUAL(c.dominantPreviousNeighbour( 20 ), 10);
}

BOOST_AUTO_TEST_SUITE_END()
