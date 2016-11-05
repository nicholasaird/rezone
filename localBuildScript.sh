export COMPILER=clang++-3.9
export BUILD_TYPE=Debug

if [ ! -d build ]; then
    mkdir build
    cd build
    cmake -DCMAKE_CXX_COMPILER=${COMPILER} -DCMAKE_BUILD_TYPE=${BUILD_TYPE} -GNinja ..
    cd ..
fi

touch CMakeLists.txt
cd build
ninja
