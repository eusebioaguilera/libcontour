#set(MAIN_SRC main.cpp)
set(LIB_SRC 
	contour.cpp
	rect.cpp
	evaluator.cpp
	plotter.cpp
	)

#Sends the -Wall flag to the gcc compiler
add_definitions(-Wall)
#This tells CMake to create a shared lib
add_library(contour SHARED ${LIB_SRC} ${Boost_LIBRARIES})
target_link_libraries(contour mgl)
