#Specify the version being used aswell as the language
cmake_minimum_required(VERSION 2.8)
#Name your project here
project(libcontour CXX)
# Libraries
FIND_PACKAGE( Boost 1.47 COMPONENTS unit_test_framework REQUIRED )

INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )
enable_testing()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}")

ADD_SUBDIRECTORY(src)
#if(MAKE_TETS)
	ADD_SUBDIRECTORY(tests)
#endif(MAKE_TESTS)
ADD_SUBDIRECTORY(python)


