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
 
/**
 * @file rect.hpp
 * This class implements the rect object and calculates rect values a, b y c.
 * @brief This class implements the rect object and calculates rect values a, b y c.
 * @author Eusebio Aguilera
 * @version 1.0
 */
 
 
#ifndef RECT_HPP
#define RECT_HPP

#include <cmath>
#include "point.hpp"

namespace libcontour {
	class Rect {
		double _a;
		double _b;
		double _c;
	
	protected:
		// Setters are protected
		void a( double value ) { this->_a = value; }
		void b( double value ) { this->_b = value; }
		void c( double value ) { this->_c = value; }
		
	public:
		
		// Getters and setters
		double a( void ) { return this->_a; }
		double b( void ) { return this->_b; }
		double c( void ) { return this->_c; }
		
		Rect( const Point &p1, const Point &p2 );
		
		/// Returns the distance between the rect and the point p
		double distance( const Point &p );
	};
};

#endif //RECT_HPP
