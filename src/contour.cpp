/*
 * contour.cpp
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


#include "contour.hpp"

namespace libcontour {

Contour::Contour() {
	
}


/*
 * This constructor read a text file and create a contour from it. The
 * text file has the format one x-coordinate y-coordinate per line.
 * */
Contour::Contour( const std::string &path_to_file ) {
    double x = 0, y = 0;
    std::fstream fp;
    std::map< std::pair<double, double>, int > nn;
    int counter = 0;
    
    fp.open(path_to_file.c_str(), std::ios_base::in);

    if (fp) {
		/* Read the file */

		while (!fp.eof())
		{
			fp >> x >> y;

			if (!fp.eof())
			{
				Point p = Point( static_cast<double>(x), static_cast<double>(y) );
				
				// Add point to the polygon
				boost::geometry::append( this->_contour, p );
				
				// Add index to indexes
				this->_indexes[ p ] = counter;
				
				counter++;
			}
		}

		fp.close(); /* Close the file */
	}
}

Contour::Contour( std::vector<Point> points ) {
	int counter = 0;
	
	for ( std::vector<Point>::iterator it = points.begin(); it != points.end(); it++ ) {
		this->_indexes[ *it ] = counter;
		counter++;
	}
	// Assign
	boost::geometry::assign_points( this->_contour, points );
}

void Contour::markAsDominant( int pos ) {
	if ( pos < size() and pos > -1 ) {
		this->_dominants.insert( pos );
	}
}

void Contour::unMarkAsDominant( int pos ) {
	if ( pos < size() and pos > -1 ) {
		this->_dominants.erase( pos );
	}
}

Point Contour::operator[] ( int pos ) const {
	Point p;
	if ( pos < size() and pos > -1 ) {
		p = this->_contour.outer()[ pos ];
	}
	
	return p;
}

std::vector <Point> Contour::slice( int init, int end) {
	std::vector <Point> sl;
	
	if ( ( init > -1 and init < this->size() ) and ( end > -1 and end < size() ) ) {
		
		std::vector<Point>::iterator it_init, it_end, it_last, it_first;
		
		if ( init < end ) {
			// Get normal slice
			it_init = this->_contour.outer().begin() + init;
			it_end = this->_contour.outer().begin() + end;
			for ( std::vector<Point>::iterator it = it_init; it != it_end; it++ ) {
				sl.push_back( *it );
			}
			
			// Add last item
			sl.push_back( *it_end );
		} else {
			// Get a slice that cross zero position a beyond
			it_init = this->_contour.outer().begin() + init;
			it_end = this->_contour.outer().begin() + end;
			it_last = this->_contour.outer().end();
			it_first = this->_contour.outer().begin();
			for ( std::vector<Point>::iterator it = it_init; it != it_end; it++ ) {
				sl.push_back( *it );
				
				if ( it == it_last ) {
					// We have reach last item
					it = it_first;
				}
			}
			
			// Add last item
			sl.push_back( *it_end );
		}
		
	}
	
	return sl;
}


int Contour::dominantNextNeighbour( int pos ) {
	
	int neighbour = -1;
	
	std::set<int> indexes = this->dominantsIndexes();
	
	std::set<int>::iterator it = indexes.find( pos );
	
	if ( it != indexes.end() ) {
		// We have found the value
		it++;
		
		if ( it == indexes.end() ) {
			it = indexes.begin();
		}
		
		neighbour = *it;
	}
	
	return neighbour;
}

int Contour::dominantPreviousNeighbour( int pos ) {
	
	int neighbour = -1;
	
	std::set<int> indexes = this->dominantsIndexes();
	
	std::set<int>::iterator it = indexes.find( pos );
	
	if ( it != indexes.end() ) {
		// We have found the value
		if ( it == indexes.begin() ) {
			it = indexes.end();
		}
		
		it--;
		
		neighbour = *it;
	}
	
	return neighbour;
}

}
