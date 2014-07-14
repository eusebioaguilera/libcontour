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
#include <iostream>

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
    //std::map< std::pair<double, double>, int > nn;
    int counter = 0;
    
    fp.open(path_to_file.c_str(), std::ios_base::in);

    if (fp) {
		/* Read the file */

		while (!fp.eof())
		{
			fp >> x >> y;

			if (!fp.eof())
			{
				Point p = Point( static_cast<float>(x), static_cast<float>(y) );
				
				// Add point to the polygon
				//boost::geometry::append( this->_contour, p );
                this->_points.push_back( p );
				
				// Add index to indexes
                this->_indexes[ p ].push_back( counter );
				//this->_indexes[ p ] = counter;
				
				counter++;
			}
		}

		fp.close(); /* Close the file */
	}
}

Contour::Contour( std::vector<Point> points ) {
	//int counter = 0;
	
	for ( std::vector<Point>::iterator it = points.begin(); it != points.end(); it++ ) {
		//this->_indexes[ *it ] = counter;
		//counter++;
        this->_points.push_back( *it );
	}
	// Assign
	//boost::geometry::assign_points( this->_contour, points );
}

void Contour::dominant( int pos, bool value ) {
	if ( pos < size() and pos > -1 ) {
        if ( value ) {
            this->_dominants.insert( pos );
        } else {
            this->_dominants.erase( pos );
        }
	}
}

Point Contour::operator[] ( int pos ) const {
	Point p;
	if ( pos < size() and pos > -1 ) {
		p = this->_points[ pos ];
	}
	
	return p;
}

std::vector <Point> Contour::slice( int init, int end) {
	std::vector <Point> sl;
	
	if ( ( init > -1 and init < this->size() ) and ( end > -1 and end < size() ) ) {
		
		std::vector<Point>::iterator it_init, it_end, it_last, it_first;
		
		if ( init < end ) {
			// Get normal slice
			it_init = this->_points.begin() + init;
			it_end = this->_points.begin() + end;
			for ( std::vector<Point>::iterator it = it_init; it != it_end; it++ ) {
				sl.push_back( *it );
			}
			
			// Add last item
			sl.push_back( *it_end );
		} else {
			// Get a slice that cross zero position a beyond
			it_init = this->_points.begin() + init;
			it_end = this->_points.begin() + end;
			it_last = this->_points.end();
			it_first = this->_points.begin();
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


int ContourStats::distance (int i, int j) const throw () {
	int s = _x.size();
	
	return (j-i+s) % s;
}

double ContourStats::computeISEForSegment (const int i, const int j) const throw () {
	double ISE=std::numeric_limits<double>::infinity();
  
	const int npoints = distance(i, j) - 1;
	
	int jMinus1;
	
	if (npoints > 0){

		Line2D l = Line2D(_c[i], _c[j]);
		
		jMinus1 = (j-1 + _x.size()) % _x.size();
		

		
		double x, y, xx, yy, xy;
		
		if (i<jMinus1){
			x = _x[jMinus1]-_x[i];
			y = _y[jMinus1]-_y[i];
			xx = _xx[jMinus1]-_xx[i];
			yy = _yy[jMinus1]-_yy[i];
			xy = _xy[jMinus1]-_xy[i];
		} else {
			x = _x[_x.size()-1]-_x[i] + _x[jMinus1];
			y = _y[_x.size()-1]-_y[i] + _y[jMinus1];
			xx = _xx[_x.size()-1]-_xx[i] + _xx[jMinus1];
			yy = _yy[_x.size()-1]-_yy[i] + _yy[jMinus1];
			xy = _xy[_x.size()-1]-_xy[i] + _xy[jMinus1];
		}

		ISE = l.a()*l.a()*xx+l.b()*l.b()*yy+(npoints)*l.c()*l.c()+2.0*l.b()*l.c()*y+2.0*l.a()*l.c()*x+2.0*l.a()*l.b()*xy;
	} else {
		ISE = 0.0;
	}
	
	return ISE;
}

double ContourStats::computeISE (std::vector<int>& dpoints) const throw () {
	int s = dpoints.size();
	double ise = 0.0;
	
	for (int i = 0; i < s; i++){
		
		int current = dpoints[i];
		int next = dpoints[(i+1)%s];
		
		
		double temp = this->computeISEForSegment(current, next);
		
		
		ise += temp;
		
	}
	
	return ise;
}

}
