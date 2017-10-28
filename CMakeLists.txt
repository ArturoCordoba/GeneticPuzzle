cmake_minimum_required(VERSION 3.8)
project(GeneticPuzzle)

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Piece.h Node.h Matrix.h List.h UtilityProgram.h MatrixNode.h)
add_executable(GeneticPuzzle ${SOURCE_FILES})

target_link_libraries( GeneticPuzzle ${OpenCV_LIBS} )

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

find_package(SFML REQUIRED system window graphics network audio)

if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(GeneticPuzzle ${SFML_LIBRARIES})
endif()


