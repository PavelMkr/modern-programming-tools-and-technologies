cmake_minimum_required(VERSION 3.28.3)
project(SierpinskiFractal)

# release
set(SOURCE_FILES
    main.c
    fractal.c
    image.c
)

include_directories(${CMAKE_SOURCE_DIR})

add_executable(fractal ${SOURCE_FILES})

# utest
set(TEST_FILES
    test_main.c
    fractal.c
    image.c
)

include_directories(${CMAKE_SOURCE_DIR}/utest)

add_executable(test_fractal ${TEST_FILES})
