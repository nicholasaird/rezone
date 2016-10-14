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

## Compilation

### Ubuntu
Build the executables:
```shell
# Inside the project root
mkdir build
cd build
cmake ..
make
```

Run the tests:
```shell
# Inside /build
./test
```

Run the game:
```shell
# Inside /build
./rezone
```
