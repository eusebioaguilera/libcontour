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
#include <vector>
#include <set>
#include <map>
#include "point.hpp"



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

};

#endif /* CONTOUR_HPP */ 
