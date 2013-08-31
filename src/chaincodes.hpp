/*
 * chaincodes.hpp
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


#ifndef CHAINCODES_HPP
#define CHAINCODES_HPP

#include <vector>
#include <cmath>
#include "point.hpp"
#include "contour.hpp"

/**
 * @file chaincodes.hpp
 * This files contains the implementation of several chain codes lossless algorithms
 * @brief This files contains the implementation of several chain codes lossless algorithms
 * @author Eusebio Aguilera
 * @version 1.0
 */

namespace libcontour {

std::vector< int > fcc( const Contour &contour );

};

#endif /* PLOTTER_HPP */ 
