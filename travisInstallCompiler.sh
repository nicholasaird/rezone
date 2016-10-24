set -e

if [ $COMPILER = "clang++-3.9" ]; then
    echo "Installing clang++-3.9..."
    sudo add-apt-repository "deb http://llvm.org/apt/trusty/ llvm-toolchain-trusty-3.9 main"
    sudo apt-get update
    sudo apt-get install clang-3.9 lldb-3.9
fi

if [ $COMPILER = "g++-5" ]; then
    echo "Installing g++-5..."
    sudo add-apt-repository ppa:ubuntu-toolchain-r/test
    sudo apt-get update
    sudo apt-get install g++-5
fi

echo "Using compiler ${COMPILER}:"
${COMPILER} -v
