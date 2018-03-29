cmake_minimum_required(VERSION 3.0)

project(benchmarks)

# These settings, in combination with forcing cmake to use clang/clang++,
# will compile benchmarks into monolithic LLVM IR .bc files in addition
# to compiling them into executables.
# This method is ugly and imperfect, but works for me at the moment.
# Requires gold.
# Requires LLVMgold.so to be build while building LLVM, see:
# https://llvm.org/docs/GoldPlugin.html
# (basically, just use -DLLVM_BINUTILS_INCDIR=/path/to/binutils/include
# when configuring llvm)
# To get LLVM_BINUTILS_INCDIR, you need the source for your version of
# binutils. Run `gold --version`, figure out your version number, and
# then download the archive from GNU.
# You'll also have to force cmake to use clang/clang++, with:
# `CC=/path/to/clang CXX=/path/to/clang++ cmake ...`
# Easy peasy!
#
# The primary source that helped me put this together:
# https://stackoverflow.com/questions/40366875/get-llvm-ir-after-lto-linking?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -flto -O0 -save-temps -fuse-ld=gold -Wl,-plugin-opt=save-temps")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -flto -O0 -save-temps -fuse-ld=gold -Wl,-plugin-opt=save-temps")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -flto -fuse-ld=gold -save-temps -Wl,-plugin-opt=save-temps")

add_subdirectory(./SingleSource)
