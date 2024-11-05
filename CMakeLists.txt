cmake_minimum_required(VERSION 3.29)
project(CatMerge CXX)

set(CMAKE_CXX_STANDARD 23)

include(FetchContent)

function(include_dependency libName gitURL gitTag)
    # setup the declare
    FetchContent_Declare(${libName}
            GIT_REPOSITORY ${gitURL}
            GIT_TAG        ${gitTag}
            GIT_SHALLOW    TRUE
            GIT_PROGRESS   TRUE
    )

    FetchContent_MakeAvailable(${libName})
endfunction()

set(LIB1 raylib)
find_package(${LIB1} QUIET)
if (NOT ${LIB1}_FOUND)
    message(STATUS "Getting ${LIB1} from Github")
    include_dependency(${LIB1} https://github.com/raysan5/raylib.git 5.0)
else()
    message(STATUS "Using local ${LIB1}")
endif()

add_executable(CatMerge main.cpp
        Cat.cpp
        Cat.h
        Boundary.cpp
        Boundary.h
        Game.cpp
        Game.h
        Score.cpp
        Score.h
)

target_include_directories(CatMerge SYSTEM PRIVATE ${raylib_INCLUDE_DIRS})

target_link_libraries(CatMerge PRIVATE ${LIB1})
