/*
 * contour.hpp
 * 
 * Copyright 2013 Eusebio Aguilera <eusebio.aguilera@gmail.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#ifndef CONTOUR_HPP
#define CONTOUR_HPP

#include <string>
#include <fstream>
#include <cassert>
#include <vector>
#include <set>
#include <map>
#include <valarray>
#include <limits>
#include "point.hpp"
#include "rect.hpp"
#include "line2d.hpp"



namespace libcontour {


/**
 * 
 * @file point.hpp
 * Definition of the contour object. Contor object represent a contour that
 * can be draw, modified, etc.
 * @author Eusebio J. Aguilera
 * @version 1.0
 * 
 * */

class Contour {
    private:
        std::vector<Point> _points;
        std::set<int> _dominants;
        std::map< Point, std::vector<int> > _indexes;
	public:
		Contour();
		Contour( std::vector<Point> points );
		Contour( const std::string &path_to_file );
		
		//// Getters
		inline std::vector<Point> points ( void ) const { return this->_points; }
		inline std::set<int> dominantsIndexes( void ) const { return this->_dominants; }
		inline std::map< Point, std::vector<int> > indexes( void ) const { return this->_indexes; }
		
		//// Operators
		Point operator[] ( int pos ) const;
		
		///// Returns a slice from init point to end point
		std::vector <Point> slice( int init, int end);
		
		///// Returns the size of the contour in number of points
		inline int size( void ) const {  return this->_points.size(); }
		
		///// Returns the number of points that have been marked as dominant 
		inline int dominantsSize( void ) const { return this->_dominants.size(); }
		
		///// Return the index of the point p inside the contour in the order that the contour has been read
		inline std::vector<int> index_of( const Point &p ) { return this->_indexes[ p ]; }
		
		///// Set/UnSet the point as dominant
		void dominant( int pos, bool value );

		///// Returns the next point (index) marked as dominant
		int dominantNextNeighbour( int pos );
		
		///// Returns the previous point (index) marked as dominant 
		int dominantPreviousNeighbour( int pos );
	
	//private:
		//Polygon _contour;
		//std::set<int> _dominants;
		//std::map< Point, int, PointComparer > _indexes;
};

/*
 * 
 * @brief This class computes ISE value in constant time, see 
 * Juan-Carlos Perez and Enrique Vidal. Optimum polygonal approximation
 * of digitized curves. Pattern Recognition Letters, 15(8):743–750, August
 * 1994. ISSN 0167-8655. doi: 10.1016/0167-8655(94)90002-7.
 * 
 * 
 * */

class ContourStats
{
	std::valarray<double> _x, _y, _xx, _yy, _xy;
	Contour _c;
public:

	void initialize (const Contour& c) throw ()
	{
		assert (c.size()>2);
		//_c.resize(c.size());
		_c = c;
		_x.resize(c.size());
		_y.resize(c.size());
		_xx.resize(c.size());
		_yy.resize(c.size());
		_xy.resize(c.size());
		double x = c[0].x();
		double y = c[0].y();
		_x[0] = x;
		_y[0] = y;
		_xx[0] = x*x;
		_yy[0] = y*y;
		_xy[0] = x*y;
		//_c[0] = c[0];
		for (unsigned p = 1; p<c.size(); ++p)
		{
			//_c[p] = c[p];
			x = c[p].x();
			y = c[p].y();
			_x[p] = x + _x[p-1];
			_y[p] = y + _y[p-1];
			_xx[p] = x*x + _xx[p-1];
			_yy[p] = y*y + _yy[p-1];
			_xy[p] = x*y +  _xy[p-1];
		}
	}
	
	int distance (int i, int j) const throw ();
	
	double computeISE (std::vector<int>& dpoints) const throw ();
	
	double computeISEForSegment (const int i, const int j) const throw ();

	//double computeMaxDeviation (const int i, const int j, int* maxDevPoint=0) const throw ();
};

};

#endif /* CONTOUR_HPP */ 
