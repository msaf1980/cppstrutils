cmake_minimum_required( VERSION 3.5 )

# Options can be turned on and off by providing cmake with a -DOPTIONNAME=ON (or
# OFF) argument. For example, to turn off benchmarks, and use sanitize flags in
# a DEBUG build: cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DBENCH=OFF -DSANITIZE=ON ..

# Release build with custom optimization options and debuginfo"
# cmake -DCMAKE_C_FLAGS="-O2 -Werror" -DCMAKE_CXX_FLAGS="-O2 -Werror" -DCMAKE_BUILD_TYPE=Release -DDEBUGINFO=ON ..

# Override install prefix with CMAKE_INSTALL_PREFIX

# Add test files with filenames <NAME>_test.cpp or <NAME>_test.c into test dir
# Add bench files with filenames <NAME>_bench.cpp or <NAME>_bench.c into test
# dir Put tests and benchmarks into DIR_TESTS dirs Tests by glob *_test.cpp
# *_test.c Benchmarks by glob *_bench.cpp *_bench.c

# Override bin build dir with BINDIR
set(BINDIR bin)
# Override lib build dir with LIBDIR
set(LIBDIR lib)

include(${CMAKE_SOURCE_DIR}/options_init.cmake)

# Include cmake prescript from cmake dir
file(GLOB cmakeFiles cmake_pre/*.cmake)
foreach(cmakeFile ${cmakeFiles})
    message("INCLUDE ${cmakeFile}")
    include(${cmakeFile})
endforeach(cmakeFile)

project(strutils)

file(GLOB cmakeFiles cmake/*.cmake)
foreach(cmakeFile ${cmakeFiles})
    message("INCLUDE ${cmakeFile}")
    include(${cmakeFile})
endforeach(cmakeFile)

include_directories(include)

if(DEFINED ENV{DEVENV})
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(src)

# enable_testing()
include(CTest)
add_subdirectory(test)

include(${CMAKE_SOURCE_DIR}/options_print.cmake)
