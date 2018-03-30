cmake_minimum_required(VERSION 3.0)

project(benchmarks)

# These settings, in combination with forcing cmake to use clang/clang++,
# will compile benchmarks into monolithic LLVM IR .bc files in addition
# to compiling them into executables.
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -flto -O0 -save-temps -fuse-ld=gold -Wl,-plugin-opt=save-temps")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -flto -O0 -save-temps -fuse-ld=gold -Wl,-plugin-opt=save-temps")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -flto -fuse-ld=gold -save-temps -Wl,-plugin-opt=save-temps")

add_subdirectory(./SingleSource)
