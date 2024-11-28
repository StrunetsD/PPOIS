cmake_minimum_required(VERSION 3.29)
project(lab_4)

set(CMAKE_CXX_STANDARD 20)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(lab_4
        src/Graph.h
        runTests.cpp
        src/EdgeIter.h
        src/VertexIter.h
        src/IncidentEdgeIterator.h
        src/AdjacentVertexIterator.h
        tests/AdjacentVertexIteratorTest.cpp
        tests/EdgeIterTest.cpp
        tests/GraphTest.cpp
        tests/IncidentEdgeIteratorTest.cpp
        tests/VertexIterTest.cpp
)

add_executable(AdjacentVertexIteratorTest
        tests/AdjacentVertexIteratorTest.cpp)
target_link_libraries(AdjacentVertexIteratorTest ${GTEST_LIBRARIES} pthread)

add_executable(VertexIterTest
        tests/VertexIterTest.cpp)
target_link_libraries(VertexIterTest ${GTEST_LIBRARIES} pthread)

add_executable(IncidentEdgeIteratorTest
        tests/IncidentEdgeIteratorTest.cpp)
target_link_libraries(IncidentEdgeIteratorTest ${GTEST_LIBRARIES} pthread)

add_executable(GraphTest
        tests/GraphTest.cpp)
target_link_libraries(GraphTest ${GTEST_LIBRARIES} pthread)

add_executable(EdgeIterTest
        tests/EdgeIterTest.cpp)
target_link_libraries(EdgeIterTest ${GTEST_LIBRARIES} pthread)

enable_testing()
add_test(NAME VertexIterTest COMMAND VertexIterTest)
add_test(NAME GraphTest COMMAND GraphTest)
add_test(NAME AdjacentVertexIteratorTest COMMAND AdjacentVertexIteratorTest)
add_test(NAME EdgeIterTest COMMAND EdgeIterTest)
add_test(NAME IncidentEdgeIteratorTest COMMAND IncidentEdgeIteratorTest)

target_link_libraries(lab_4 ${GTEST_LIBRARIES} pthread)