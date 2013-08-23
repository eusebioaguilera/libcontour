/*
 * plotter.cpp
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


#include "plotter.hpp"

namespace libcontour {

Plotter::Plotter( const Contour &contour, std::string filename ) {
	std::stringstream legend_creator;
	
	this->_contour = contour;
	this->_filename = filename;
	this->_style = "k#s "; // Only points
	this->_onlyContour = false;
	this->_drawLegend = true;

	// Default legend
	legend_creator << "Dominant points (" << _contour.dominantsSize() << ")";
	
	this->_legend = legend_creator.str();
}

void Plotter::writeToEPS( void ) {
	// Plotting
	mglData xdat1( _contour.size() + 1), ydat1( _contour.size() +1 );	// data for plotting
	mglData xdat2( _contour.dominantsSize() + 1 ) , ydat2 ( _contour.dominantsSize() + 1 );	// data for plotting
	mglData xdat3( 2 ) , ydat3 ( 2 );	// data for plotting
	
	for ( int i = 0; i < _contour.size(); i++ ) {
		Point p = _contour[ i ];
		xdat1.a[ i ] = p.x();
		ydat1.a[ i ] = p.y();
	}
	
	// First point
	Point p = _contour[ 0 ];
	xdat1.a[ _contour.size() ] = p.x();
	ydat1.a[ _contour.size() ] = p.y();
	
	xdat3.a[ 0 ] = p.x();
	ydat3.a[ 0 ] = p.y();
	
	std::set<int> dm = _contour.dominantsIndexes();
	int counter = 0;
	
	for (std::set<int>::iterator it = dm.begin(); it != dm.end(); it++) {
		Point p = _contour[*it];
		xdat2.a[ counter ] = p.x();
		ydat2.a[ counter ] = p.y();
		counter++;
	}
	
	std::set<int>::iterator first = dm.begin();

	p = _contour[ *first ];
	xdat2.a[ _contour.dominantsSize() ] = p.x();
	ydat2.a[ _contour.dominantsSize() ] = p.y();
	
	
	
	mglGraphPS gr;
	gr.XRange( xdat1 );
	gr.YRange( ydat1 );
	
	if ( !this->_onlyContour ) {
		
		gr.AddLegend( "Original contour", "k.-");
		gr.AddLegend( this->_legend.c_str() , this->_style.c_str( ) );
	
		//gr.AddLegend( "Init point", "gs ");
		gr.Plot( xdat1, ydat1, "k.-" );
		gr.Plot( xdat2, ydat2, this->_style.c_str( ) );
		//gr.Plot( xdat3, ydat3, "gs " );
	
		if ( this->_drawLegend ) {
			gr.Legend( -0.25,1 );
		}
		
	} else {
		gr.Plot( xdat1, ydat1, "k-" );
	}
	
	// Fichero EPS
	gr.WriteEPS( _filename.c_str() );

}


void Plotter::onlyPoints( bool only ) {
	
	if ( only ) {
		this->_style = "k#s "; // Only points
	} else {
		this->_style = "h#s;"; // Dashed line grey
	}
}

void Plotter::onlyContour( bool only ) {
	this->_onlyContour = only;
}

void Plotter::drawLegend( bool draw ) {
	this->_drawLegend = draw;
}

};
