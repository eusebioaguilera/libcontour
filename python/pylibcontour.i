/* File : example.i */
%module pylibcontour
%{
/* Put headers and other declarations here */
#include "../src/point.hpp"
#include "../src/contour.hpp"
#include "../src/rect.hpp"
#include "../src/evaluator.hpp"
#include "../src/plotter.hpp"
#include "../src/chaincodes.hpp"
#include "../src/algorithms.hpp"
#include "../src/line2d.hpp"
%}

%include "std_string.i"
%include "std_vector.i"
%include "std_set.i"
%include "std_map.i"
%include "../src/point.hpp"

namespace std {
    %template (PointVector) vector<libcontour::Point>;
    %template (SetInt) set<int>;
    %template (DominantIndexes) map<libcontour::Point, vector< int > >;
    %template (VectorInt) vector<int>;
    %template (ItemTable) std::vector< double>;
    %template (TableDouble) std::vector<std::vector<double> >;
}

%extend libcontour::Contour {
    libcontour::Point __getitem__(unsigned int i) {
        return (*($self))[i];
    }
}

%include "../src/contour.hpp"
%include "../src/rect.hpp"
%include "../src/evaluator.hpp"
%include "../src/plotter.hpp"
%include "../src/chaincodes.hpp"
%include "../src/algorithms.hpp"
%include "../src/line2d.hpp"
