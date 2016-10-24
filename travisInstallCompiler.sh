set -e

if [ $COMPILER = "clang++-3.9" ]; then
    sudo add-apt-repository "deb http://llvm.org/apt/trusty/ llvm-toolchain-trusty-3.9 main"
    apt-get update
    apt-get install clang-3.9 lldb-3.9
fi

if [ $COMPILER = "g++-5" ]; then
    sudo apt-get install g++-5
fi

echo "Using compiler ${COMPILER}:"
${COMPILER} -v
