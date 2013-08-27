/* File : example.i */
%module pylibcontour
%{
/* Put headers and other declarations here */
#include "../src/point.hpp"
#include "../src/rect.hpp"
#include "../src/contour.hpp"
#include "../src/evaluator.hpp"
#include "../src/plotter.hpp"
%}

%include "std_string.i"
%include "std_vector.i"
%include "../src/point.hpp"
%include "../src/rect.hpp"
%include "../src/contour.hpp"
%include "../src/evaluator.hpp"
%include "../src/plotter.hpp"
