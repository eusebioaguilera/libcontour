/*
 * point.hpp
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
 * 
 * @file point.hpp
 * Definition of the main object of the library. A point is the main object
 * of the libcontour library.
 * @author Eusebio J. Aguilera
 * @version 1.0
 * 
 * */

#ifndef POINT_HPP
#define POINT_HPP

#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/geometries/segment.hpp>

namespace libcontour {

typedef boost::geometry::model::d2::point_xy<double> Point;

struct PointComparer {
	inline bool operator() ( const Point &p1, const Point &p2 ) {
		if ( p1.x() < p2.x() ) {
			return true;
		} else if ( p1.x() == p2.x() and p1.y() < p2.y() ) {
			return true;
		} else {
			return false;
		}
	}
};

};

#endif /* POINT_HPP */ 
