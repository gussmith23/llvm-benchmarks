The benchmarks in this repository are meant to be compiled into monolithic LLVM IR files, for use in testing optimization/analysis passes.

## Dependencies
- GNU gold
- LLVMgold.so, which is built while building LLVM. See [this link](https://llvm.org/docs/GoldPlugin.html). (Basically, just use -DLLVM_BINUTILS_INCDIR=/path/to/binutils/include when configuring LLVM)
- To provide an LLVM_BINUTILS_INCDIR, you need the source for your version of binutils. Run `gold --version`, figure out your version number, and then download the archive from GNU
- You need to force cmake to use clang/clang++, with `CC=/path/to/clang CXX=/path/to/clang++ cmake ...`

## Building
```shell
git clone https://github.com/gussmith23/llvm-benchmarks
cd llvm-benchmarks
mkdir build && cd build
CC=clang CXX=clang++ cmake ..
make
```
Search the resulting file structure for LLVM .bc files. They should be in the same directory as the corresponding benchmark binary.


The primary source that helped me put this together [is here.](https://stackoverflow.com/questions/40366875/get-llvm-ir-after-lto-linking?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa)
