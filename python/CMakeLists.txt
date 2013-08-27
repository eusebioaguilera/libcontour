# This is a CMake example for Python

FIND_PACKAGE(SWIG REQUIRED)
INCLUDE(${SWIG_USE_FILE})

FIND_PACKAGE(PythonLibs)
INCLUDE_DIRECTORIES(${PYTHON_INCLUDE_PATH})

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})

SET(CMAKE_SWIG_FLAGS "")

SET_SOURCE_FILES_PROPERTIES(pylibcontour.i PROPERTIES CPLUSPLUS ON)
SWIG_ADD_MODULE(pylibcontour python pylibcontour.i ../src/rect.cpp ../src/contour.cpp ../src/evaluator.cpp ../src/plotter.cpp)
SWIG_LINK_LIBRARIES(pylibcontour ${PYTHON_LIBRARIES} -lmgl)
