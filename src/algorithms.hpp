/*
 * algorithms.hpp
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


#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include <vector>
#include <cmath>
#include <iostream>
#include "point.hpp"
#include "contour.hpp"
#include "chaincodes.hpp"

/**
 * @file algorithms.hpp
 * This files contains the implementation of several algorithms applied to 2-D contours
 * @brief This files contains the implementation of several algorithms applied to 2-D contours
 * @author Eusebio Aguilera
 * @version 1.0
 */

namespace libcontour {

// This algorithm computes the breakpoints extraction of a contour given
std::vector< int > breakpoints( const Contour &contour );

// This algorithm computes a matrix with al values of distances
std::vector< std::vector< double > > computeDistancesMatrix( const Contour &cnt );

};

#endif /* PLOTTER_HPP */
