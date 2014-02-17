/*
 * algorithms.cpp
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


#include "algorithms.hpp"

namespace libcontour {

/*
 * This method implements the breakpoints extraction
 * */

std::vector < int > breakpoints ( const Contour &contour ) {

    int nPoints = contour.size( );
    int current, next;
    std::vector< int > result; // Breakpoints
    std::vector< int > chain; // Chain codes
    int ccc = 0; // Current Chain Code
    bool second = false;

    // Compute Freeman chain codes
    chain = fcc( contour );

    current = 0;
    next = current;

    while ( not second ) {
		while ( chain[ current ] == chain[ next ] ) {
			next = ( next + 1 ) % nPoints;

			if ( next == 0 ) {
				second = true;
			}
		}

		result.push_back( next );

		current = next;

	}

    return result;

}

std::vector< std::vector< double > > computeDistancesMatrix( const Contour &cnt ) {
    std::vector< std::vector< double > > table;

    int cSize = cnt.size();

    //table.reserve( cSize );


    for ( int i = 0; i < cSize; i++ ) {
        std::vector< double > item;

        //item.reserve( cSize );

        Point pi = cnt[i];

        item.clear();

        for ( int j = 0; j < cSize; j++ ) {


            double sum = 0.0;

            Point pj = cnt[j];

            if ( i != j ) {

                int k = (i+1)%cSize;
                int k_end = i+( (j-i) % cSize);

                while ( k != k_end ) {

                    Point pk = cnt[k];

                    sum += pow( ( ( pk.x() - pi.x() ) * ( pj.y() - pi.y() ) - ( pk.y() - pi.y() ) * ( pj.x() - pi.x() ) ) , 2 ) / ( pow( (pi.x() - pj.x() ) ,2) + pow( ( pi.y() - pj.y() ) ,2) );

                    k = (k + 1) % cSize;
                }

            }

            item.push_back( sum );

            ///std::cout << "Items " << i << ", " << j << " = " << sum << std::endl;
        }

        table.push_back( item );
    }

    ///std::cout << "Items " << table[59][58] << std::endl;

    return table;
}

};
