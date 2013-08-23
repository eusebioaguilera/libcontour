#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Suites
#include <boost/test/unit_test.hpp>
#include <rect.hpp>
#include <point.hpp>

BOOST_AUTO_TEST_SUITE(Rect)
BOOST_AUTO_TEST_CASE(constructors)
{
	libcontour::Point p1, p2;
	
	p1.x( 1 ); p1.y( 1 );
	p2.x( 0 ); p2.y( 0 );
	
	libcontour::Rect r = libcontour::Rect( p1, p2 );
}

BOOST_AUTO_TEST_CASE(distance)
{
	libcontour::Point p1, p2, p3;
	
	p1.x( 1 ); p1.y( 0 );
	p2.x( 0 ); p2.y( 0 );
	
	libcontour::Rect r = libcontour::Rect( p1, p2 );
	
	p3.x( 0 ); p3.y( 1 );
	
	BOOST_CHECK_EQUAL(r.distance( p3 ), 1 );
}

BOOST_AUTO_TEST_SUITE_END()
