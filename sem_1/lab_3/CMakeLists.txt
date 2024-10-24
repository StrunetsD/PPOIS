cmake_minimum_required(VERSION 3.29)
project(lab_3)

set(CMAKE_CXX_STANDARD 20)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fprofile-arcs -ftest-coverage")
endif()

add_subdirectory(googletest)
include_directories(googletest/googletest/include)

add_executable(
        lab_3
        runTest.cpp
        src/Human.cpp
        src/Employee.cpp
        src/Developer.cpp
        src/QA.cpp
        src/LevelDesigner.cpp
        src/CharacterDesigner.cpp
        src/MechanicsDesigner.cpp
        src/AIEngineer.cpp
        src/Animator.cpp
        src/SoundDesigner.cpp
        src/UIUXDesigner.cpp
        src/Artist.cpp
        src/ProjectManager.cpp
        src/GameProject.cpp
        src/Bank.cpp
        tests/HumanTest.cpp
        tests/EmployeeTest.cpp
        tests/ArtistTest.cpp
        tests/BankTest.cpp
        tests/CharacterDesignerTest.cpp
        tests/DeveloperTest.cpp
        tests/GameProjectTest.cpp
        tests/LevelDesignerTest.cpp
        tests/MechanicsDesignerTest.cpp
        tests/AIEngineerTest.cpp
        tests/ProjectManagerTest.cpp
        tests/UIUXDesignerTest.cpp
        tests/SoundDesignerTest.cpp
        tests/QATest.cpp
)

target_link_libraries(lab_3 gtest gtest_main pthread)

add_executable(QATest tests/QATest.cpp
        tests/QATest.cpp)
target_link_libraries(QATest gtest gtest_main pthread)

add_executable(SoundDesignerTest tests/SoundDesignerTest.cpp)
target_link_libraries(SoundDesignerTest gtest gtest_main pthread)

add_executable(UIUXDesignerTest tests/UIUXDesignerTest.cpp)
target_link_libraries(UIUXDesignerTest gtest gtest_main pthread)

add_executable(HumanTest tests/HumanTest.cpp)
target_link_libraries(HumanTest gtest gtest_main pthread)

add_executable(AIEngineerTest tests/AIEngineerTest.cpp)
target_link_libraries(AIEngineerTest gtest gtest_main pthread)

add_executable(EmployeeTest tests/EmployeeTest.cpp)
target_link_libraries(EmployeeTest gtest gtest_main pthread)

add_executable(ArtistTest tests/ArtistTest.cpp)
target_link_libraries(ArtistTest gtest gtest_main pthread)

add_executable(BankTest tests/BankTest.cpp)
target_link_libraries(BankTest gtest gtest_main pthread)

add_executable(CharacterDesignerTest tests/CharacterDesignerTest.cpp)
target_link_libraries(CharacterDesignerTest gtest gtest_main pthread)

add_executable(DeveloperTest tests/DeveloperTest.cpp)
target_link_libraries(DeveloperTest gtest gtest_main pthread)

add_executable(GameProjectTest tests/GameProjectTest.cpp)
target_link_libraries(GameProjectTest gtest gtest_main pthread)

add_executable(LevelDesignerTest tests/LevelDesignerTest.cpp)
target_link_libraries(LevelDesignerTest gtest gtest_main pthread)

add_executable(MechanicsDesignerTest tests/MechanicsDesignerTest.cpp)
target_link_libraries(MechanicsDesignerTest gtest gtest_main pthread)

add_executable(ProjectManagerTest tests/ProjectManagerTest.cpp
        tests/ProjectManagerTest.cpp
        tests/ProjectManagerTest.cpp)
target_link_libraries(ProjectManagerTest gtest gtest_main pthread)

enable_testing()
add_test(NAME HumanTest COMMAND HumanTest)
add_test(NAME AIEngineerTest COMMAND AIEngineerTest)
add_test(NAME EmployeeTest COMMAND EmployeeTest)
add_test(NAME ArtistTest COMMAND ArtistTest)
add_test(NAME BankTest COMMAND BankTest)
add_test(NAME CharacterDesignerTest COMMAND CharacterDesignerTest)
add_test(NAME DeveloperTest COMMAND DeveloperTest)
add_test(NAME GameProjectTest COMMAND GameProjectTest)
add_test(NAME LevelDesignerTest COMMAND LevelDesignerTest)
add_test(NAME MechanicsDesignerTest COMMAND MechanicsDesignerTest)
add_test(NAME ProjectManagerTest COMMAND ProjectManagerTest)
add_test(NAME SoundDesignerTest COMMAND SoundDesignerTest)
add_test(NAME UIUXDesignerTest COMMAND UIUXDesignerTest)
add_test(NAME QATest COMMAND QATest)