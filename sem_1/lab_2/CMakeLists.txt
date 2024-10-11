cmake_minimum_required(VERSION 3.29)
project(lab_2)

set(CMAKE_CXX_STANDARD 20)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(lab_2
        cmake-build-debug/main.cpp
        cmake-build-debug/ArtGallery.cpp
        cmake-build-debug/Artist.cpp
        cmake-build-debug/Painting.cpp
        cmake-build-debug/Client.cpp
        cmake-build-debug/Transaction.cpp
        cmake-build-debug/Curator.cpp
        cmake-build-debug/Security.cpp
        cmake-build-debug/Workers.cpp
        cmake-build-debug/Administrator.cpp
        cmake-build-debug/Bank.cpp
        cmake-build-debug/Event.cpp
        cmake-build-debug/Category.cpp
        cmake-build-debug/Review.cpp
        cmake-build-debug/ApplicationManager.cpp
        cmake-build-debug/Guide.cpp
        cmake-build-debug/Tour.cpp
        Testing/AdministratorTest.cpp
        Testing/SecurityTest.cpp
        Testing/ArtGalleryTest.cpp
        Testing/CuratorTest.cpp
        Testing/PaintingTest.cpp
        Testing/ArtistTest.cpp
        Testing/BankTest.cpp
        Testing/CategoryTest.cpp
        Testing/ClientTest.cpp
        Testing/EventTest.cpp
        Testing/TransactionTest.cpp
        Testing/WorkersTest.cpp
        Testing/ReviewTest.cpp

)



add_executable(ReviewTest
        Testing/ReviewTest.cpp)
target_link_libraries(ReviewTest ${GTEST_LIBRARIES} pthread)

add_executable(TransactionTest
        Testing/TransactionTest.cpp)
target_link_libraries(TransactionTest ${GTEST_LIBRARIES} pthread)

add_executable(WorkersTest
        Testing/WorkersTest.cpp
        Testing/WorkersTest.cpp)
target_link_libraries(WorkersTest ${GTEST_LIBRARIES} pthread)

add_executable(ClientTest
        Testing/ClientTest.cpp)
target_link_libraries(ClientTest ${GTEST_LIBRARIES} pthread)

add_executable(EventTest
        Testing/EventTest.cpp
        Testing/EventTest.cpp)
target_link_libraries(EventTest ${GTEST_LIBRARIES} pthread)

add_executable(AdministratorTest
      Testing/AdministratorTest.cpp)
target_link_libraries(AdministratorTest ${GTEST_LIBRARIES} pthread)

add_executable(CategoryTest
        Testing/CategoryTest.cpp)
target_link_libraries(CategoryTest ${GTEST_LIBRARIES} pthread)

add_executable(BankTest
        Testing/BankTest.cpp)
target_link_libraries(BankTest ${GTEST_LIBRARIES} pthread)

add_executable(ArtistTest
        Testing/ArtistTest.cpp)
target_link_libraries(ArtistTest ${GTEST_LIBRARIES} pthread)

add_executable(CuratorTest Testing/CuratorTest.cpp
       Testing/CuratorTest.cpp)
target_link_libraries(CuratorTest ${GTEST_LIBRARIES} pthread)

add_executable(SecurityTest Testing/SecurityTest.cpp
       Testing/SecurityTest.cpp)
target_link_libraries(SecurityTest ${GTEST_LIBRARIES} pthread)

add_executable(ArtGalleryTest Testing/ArtGalleryTest.cpp
       Testing/ArtGalleryTest.cpp)
target_link_libraries(ArtGalleryTest ${GTEST_LIBRARIES} pthread)

add_executable(PaintingTest Testing/PaintingTest.cpp
      Testing/PaintingTest.cpp
        Testing/PaintingTest.cpp)
target_link_libraries(PaintingTest ${GTEST_LIBRARIES} pthread)

enable_testing()
add_test(NAME AdministratorTest COMMAND AdministratorTest)
add_test(NAME CuratorTest COMMAND CuratorTest)
add_test(NAME SecurityTest COMMAND SecurityTest)
add_test(NAME ArtGalleryTest COMMAND ArtGalleryTest)
add_test(NAME PaintingTest COMMAND PaintingTest)
add_test(NAME ArtistTest COMMAND ArtistTest)
add_test(NAME BankTest COMMAND BankTest)
add_test(NAME CategoryTest COMMAND CategoryTest)
add_test(NAME ClientTest COMMAND ClientTest)
add_test(NAME EventTest COMMAND EventTest)
add_test(NAME TransactionTest COMMAND TransactionTest)
add_test(NAME WorkersTest COMMAND WorkersTest)
add_test(NAME ReviewTest COMMAND ReviewTest)

target_link_libraries(lab_2 ${GTEST_LIBRARIES} pthread)

