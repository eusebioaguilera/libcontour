/*
 * rect.cpp
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

#include "rect.hpp"

namespace libcontour {

Rect::Rect( const Point &p1, const Point &p2 ) {
	// Init values
			
	a( p1.y() - p2.y() );
	b( p2.x() - p1.x() );
	c( p1.x() * ( -( p1.y() - p2.y() ) ) + p1.y() * ( -( p2.x() - p1.x() ) ) ) ;
}

double Rect::distance( const Point &p ) {
	return fabs( a() * p.x() + b() * p.y() + c() ) / sqrt( a() * a() + b() * b() );
}

};
