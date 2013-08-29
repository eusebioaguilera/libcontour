/*
 * plotter.hpp
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


#ifndef PLOTTER_HPP
#define PLOTTER_HPP

#include "contour.hpp"

#include <set>

// MathGL plotting
#include <mgl/mgl.h>
#include <mgl/mgl_eps.h>
#include <string>
#include <sstream>

/**
 * @file plotter.hpp
 * This class implements functionality for drawing contours, polygonal approximations, etc
 * @brief This class implements functionality for drawing contours, polygonal approximations, etc
 * @author Eusebio Aguilera
 * @version 1.0
 */

namespace libcontour {

class Plotter
{
	public:
		Plotter( const Contour &contour, std::string filename );
		
		/// Save draw to file EPS
		void writeToEPS( void );
		
		/// Draw only points of the contour
		void onlyPoints( bool only );
		
		/// Draw only contour
		void onlyContour( bool only );
		
		inline void useStyleForDominants( std::string style ) { this->_style = style; };
		inline void useLegendDominants( std::string legend ) { this->_legend = legend; };
		
		void drawLegend( bool draw );
			
	private:
		/* add your private declarations */
		Contour _contour;
		std::string _filename;
		std::string _style;
		std::string _legend;
		bool _onlyContour;
		bool _drawLegend;
};

};

#endif /* PLOTTER_HPP */ 
