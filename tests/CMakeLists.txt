set(TEST_CONTOUR_SRC test_contour.cpp)
set(TEST_CONTOUR_BIN test_contour)

set(TEST_RECT_SRC test_rect.cpp)
set(TEST_RECT_BIN test_rect)

set(TEST_EVALUATOR_SRC test_evaluator.cpp)
set(TEST_EVALUATOR_BIN test_evaluator)

#Sends the -Wall flag to the gcc compiler
add_definitions(-Wall)

include_directories (${PROJECT_SOURCE_DIR}/src)

#add_library(contour SHARED ${LIB_SRC} ${Boost_LIBRARIES})
add_executable(${TEST_CONTOUR_BIN} ${TEST_CONTOUR_SRC})
target_link_libraries(${TEST_CONTOUR_BIN} contour ${Boost_LIBRARIES})

add_executable(${TEST_RECT_BIN} ${TEST_RECT_SRC})
target_link_libraries(${TEST_RECT_BIN} contour ${Boost_LIBRARIES})

add_executable(${TEST_EVALUATOR_BIN} ${TEST_EVALUATOR_SRC})
target_link_libraries(${TEST_EVALUATOR_BIN} contour ${Boost_LIBRARIES})


add_test(NAME test_Contour WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/data COMMAND test_contour)
