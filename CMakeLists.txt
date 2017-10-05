cmake_minimum_required(VERSION 3.8)
project(GeneticPuzzle)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp List.cpp List.h Class1.cpp Class1.h)
add_executable(GeneticPuzzle ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(GeneticPuzzle ${SFML_LIBRARIES})
endif()

