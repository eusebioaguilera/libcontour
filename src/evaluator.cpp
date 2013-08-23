/*
 * evaluator.cpp
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


/**
 * @file evaluator.cpp
 * Method's implementation of the Evaluator class
 * @brief Method's implementation of the Evaluator class
 * @author Eusebio Aguilera
 * @version 1.0
 */


#include "evaluator.hpp"

namespace libcontour {

Evaluator::Evaluator() {
	_cr = 0.0;
	_ise = 0.0;
}

/*
 * General constructor
 * @param contour Contour on which we are going to calculate the evaluator
 * 
 * */

Evaluator::Evaluator( const Contour& contour ) {
	
	// Calculate compression
	// CR = Number of points of the contour / Number of dominant points
	int nPoints, nDominants;
	nPoints = contour.size();
	nDominants = contour.dominantsSize();
	//bool second = false;
	Point current, next, first;
	double dp, max_dp = 0.0, dp_sum = 0.0;
	
	if ( nPoints > 0 and nDominants > 0 ) {
		this->_cr = (double) nPoints / (double) nDominants;
	} else {
		this->_cr = 0.0;
	}
	
	/*
	 * Calculate the sum of square error of the distance between the rect
	 * of each pair of dominant points and the projection of each point
	 * contained inside those two dominant points
	 * */ 
	 
	 std::set<int> dIndex = contour.dominantsIndexes();
	 std::set<int>::iterator current_it = dIndex.begin();
	 std::set<int>::iterator next_it;
	 std::set<int>::iterator last_it = dIndex.end();
	 last_it--; // Last value
	 do {
		 
		 if ( current_it != last_it ) {
			 next_it = current_it;
			 next_it++;
		 } else {
			 next_it = dIndex.begin();
		 }
		 
		 
		 current = contour[ *current_it ];
		 next = contour[ *next_it ];
		 //Segment seg = Segment( current, next );
		 libcontour::Rect rect = libcontour::Rect( current, next );
		 // Sum the square distance between segment seg and points between 
		 // current and next
		 //std::cout << "[" << *current_it+1 << ", " << *next_it+1 << "]" << std::endl;

		 for ( int i = (*current_it + 1) % nPoints; i != *next_it; i = ( i + 1 ) % nPoints ) {
			if ( i >= contour.size() ) {
				i = 0;
			}
			//std::cout << i << ", ";
			
			//dp = boost::geometry::distance( contour[ i ], seg );
			dp = rect.distance( contour[ i ] );
			
			//std::cout << i+1 << " --> " << dp << std::endl;
			//std::cout << "Distance from point(" << contour[i].x() << ", " << contour[i].y() << ") to Segment [(" << current.x() << ", " << current.y() << "), (" << next.x() << ", " << next.y() << ")]" << " --> " << dp << std::endl;
			 
			if ( dp > max_dp ) {
				max_dp = dp;
			}
			 
			dp_sum = dp_sum + pow( dp, 2 );
		 }
		 
		 //std::cout << "]" << std::endl;
		 
		 current_it++;
	 } while ( current_it != dIndex.end() );
	 
	 this->_ise = dp_sum;
	 this->_emax = max_dp;
}

};
