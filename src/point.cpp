/*
 * point.cpp
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

#include "point.hpp"

namespace libcontour {
    
    Point::Point( void ) {
    }
    
    Point::Point( float value_x, float value_y ) {
        this->x( value_x );
        this->y( value_y );
    }
    
    double Point::distance( Point p ) {
        return sqrt( pow( p.x() - this->x(), 2 ) + pow( p.y() - this->y(), 2 ) );
    }
    
    bool Point::operator==( const Point &p ) {
        if ( this->x() == p.x() && this->y() == p.y() ) {
            return true;
        }
        
        return false;
    }
    
    bool Point::operator<( const Point &p ) {
        if ( this->x() < p.x() ) {
			return true;
		} else if ( this->x() == p.x() and this->y() < p.y() ) {
			return true;
		} else {
			return false;
		}
    }
};
