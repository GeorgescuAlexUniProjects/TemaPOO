cmake_minimum_required (VERSION 3.8)

project ("Tema_1")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall -pedantic")
if(CMAKE_COMPILER_IS_GNUCXX)
    message(STATUS "GCC detected, adding compile flags")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98 -pedantic -Wall -Wextra -Weffc++ -Werror")
endif(CMAKE_COMPILER_IS_GNUCXX)

add_executable (Tema_1 "Tema_1.cpp" "Tema_1.h" "carte.h" "carte.cpp" "editura.cpp" "editura.h" "autor.h" "autor.cpp")