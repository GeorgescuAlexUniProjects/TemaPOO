cmake_minimum_required (VERSION 3.8)

project ("TemaPOO")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall -pedantic")
if(CMAKE_COMPILER_IS_GNUCXX)
    message(STATUS "GCC detected, adding compile flags")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98 -pedantic -Wall -Wextra -Weffc++ -Werror")
endif(CMAKE_COMPILER_IS_GNUCXX)

add_executable (TemaPOO "TemaPOO.cpp" "TemaPOO.h" "carte.cpp"  "carte.h" "autor.cpp" "autor.h" "editura.cpp" "editura.h")