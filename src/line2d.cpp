/*
 * line2d.cpp
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


#include "line2d.hpp"

namespace libcontour {

Line2D::Line2D(const Point& p1, const Point& p2) {
			_a = p2.y() - p1.y();
			_b = -(p2.x() - p1.x());
			_c = (_b*p2.y() + _a*p2.x());
			double mod = sqrt(_a*_a + _b*_b);
			_a = _a/mod;
			_b = _b/mod;
			_c = _c/mod;
}


};
