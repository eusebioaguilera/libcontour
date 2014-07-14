/*
 * line2d.hpp
 * 
 * Copyright 2014 Eusebio Aguilera <eusebio.aguilera@gmai.com>
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


#ifndef LINE2D_HPP
#define LINE2D_HPP

#include "point.hpp"

namespace libcontour {
	
class Line2D {
		double _a;
		double _b;
		double _c;
	public:
		//Line2D();
		Line2D(const Point& p1, const Point& p2);
		
		inline double a(void) {return _a;}
		inline double b(void) {return _b;}
		inline double c(void) {return _c;}
		
		double distance(const Point& p);
		
	};
	
};

#endif /* LINE2D_HPP */ 
