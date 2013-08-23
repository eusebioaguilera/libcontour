/*
 * evaluator.hpp
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
 * @file evaluator.hpp
 * Evaluator class definition
 * @brief Evaluator class definition
 * @author Eusebio Aguilera
 * @version 1.0
 */


#ifndef EVALUATOR_HPP
#define EVALUATOR_HPP

#include <cmath>
// CounterStatistics
#include <cassert>
#include <iostream>
#include <vector>
#include <valarray>
// CounterStatistics
#include "rect.hpp"
#include "contour.hpp"

/**
   * 
   * @mainpage evaluator.hpp
   * @author   Eusebio Aguilera
   * @version  1.0
   * @date     23-Feb-2013
   * 
   * This class implements calculation of the evaluator commonly used in
   * this area. The following evaluators are calculated into this evaluator.
   * 
   * 1. ISE
   * 2. ISE/CR
   * 3. ISE/CR²
   * 4. ISE/CR³
   * 5. EMAX
   * 6. FOM
*/


namespace libcontour {

class Evaluator
{
	public:
		Evaluator();
		
		Evaluator( const Contour& contour );
		
		// Getters
		inline double cr( void ) { return this->_cr; }
		inline double ise( void ) { return this->_ise; }
		inline double emax( void ) { return this->_emax; }
		inline double ise_cr( void ) { if ( _cr > 0 ) { return _ise / _cr; } else { return 0.0; } }
		inline double ise_cr2( void ) { if ( _cr > 0 ) { return _ise / pow( _cr, 2 ); } else { return 0.0; } }
		inline double ise_cr3( void ) { if ( _cr > 0 ) { return _ise / pow( _cr, 3 ); } else { return 0.0; } }
		inline double fom( void ) { if ( _ise > 0 ) { return _cr / _ise; } else { return 0.0; } }
			
	private:
		/* Private stuff */
		double _cr;
		double _ise;
		double _emax;
};


};

#endif /* EVALUATOR_HPP */ 
