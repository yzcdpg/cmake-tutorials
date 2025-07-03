cmake_minimum_required(VERSION 3.28)

add_library(MathFunctions STATIC MathFunctions.cpp)

option(USE_MYMATH "Use custom math functions" ON)

if(USE_MYMATH)
    target_compile_definitions(MathFunctions PRIVATE USE_MYMATH)
    add_library(SqrtLibrary STATIC mysqrt.cpp)
    target_link_libraries(MathFunctions PRIVATE SqrtLibrary)
endif()


