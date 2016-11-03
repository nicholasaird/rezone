[![Build Status](https://img.shields.io/travis/nicholasaird/rezone/master.svg?style=flat-square)](https://travis-ci.org/nicholasaird/rezone)
[![Codecov](https://img.shields.io/codecov/c/github/nicholasaird/rezone.svg?style=flat-square)](https://codecov.io/gh/nicholasaird/rezone)

# Rezone

## Description
An open-ended city simulator where you control the zoning and watch the city grow!

## Project download
The project contains submodules (other git projects), so you can download the code with either
```shell
git clone https://github.com/nicholasaird/rezone.git
git submodule update --init --recursive
```
or
```shell
git clone --recursive https://github.com/nicholasaird/rezone.git
```

## Compilation (Linux)
The following is intended for Ubuntu, but should work on other distributions.

### Programs needed for building

#### Required
- Compiler with c++11 and regex support. The following work:
    - g++ (4.9 or higher)
    - clang++ (any recent version)
- cmake

#### Optional
- ninja (optional alternative to `make`)
- stdlibc++ (if you are using clang, in order to have access to the regex library)

### Building
To build using your system's default compiler and make:
```shell
# Inside the project root
mkdir build
cd build
cmake ..
make
```

For a faster build, you can use ninja:
```shell
mkdir build
cd build
cmake -GNinja ..
ninja
```

To specify the compiler, use the flag ```-DCMAKE_CXX_COMPILER=<compiler name>``` with cmake.
For example:
```shell
cmake -DCMAKE_CXX_COMPILER=clang++-3.9 ..
```

### Running
Running the tests:
```shell
# Inside /build
./test
```

Running the game:
```shell
# Inside /build
./rezone
```
