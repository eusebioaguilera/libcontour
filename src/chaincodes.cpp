/*
 * chaincodes.cpp
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


#include "chaincodes.hpp"

namespace libcontour {

/*
 * This methos implements the Freeman's chain code algorithm
 * See "H. Freeman. On the encoding of arbitrary geometric configurations, 
 * IRE Transactions on Electronic Computers EC- 10(1961) 260-268." for
 * further reference.
 * */

std::vector < int > fcc ( const Contour &contour ) {
    
    int nPoints = contour.size( );
    double dx, dy, angle;
    Point current, next;
    std::vector< int > result; // Chain codes
    int ccc = 0; // Current Chain Code
    
    for ( int i = 0; i < nPoints; i++ ) {
        
        current = contour[ i ];
        next = contour[ ( i + 1 ) % nPoints ];
        
        dx = next.x( ) - current.x( );
        dy = next.y( ) - current.y( );
        
        angle = atan2( dx, dy );
        
        angle = ( 180 / M_PI ) * angle;
        
        if ( angle < 0.0 ) {
            do {
                angle += 360.0;
            } while ( angle < 0.0 );
        }
        
        if (angle > 337.5)
            ccc = 2;
        else if (angle > 292.5)
            ccc = 3;
        else if (angle > 247.5)
            ccc = 4;
        else if (angle > 202.5)
            ccc = 5;
        else if (angle > 157.5)
            ccc = 6;
        else if (angle > 112.5)
            ccc = 7;
        else if (angle > 67.5)
            ccc = 0;
        else if (angle > 22.5)
            ccc = 1;
        else
            ccc = 2;
        
        // Add to the vector 
        result.push_back( ccc );
    }
    
    return result;
    
}

};
