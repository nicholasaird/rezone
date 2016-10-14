COVERAGE_DIR=reports/coverage

mkdir -p build
cd build

# Build
echo -e "\n>>> CMake..."
cmake -DCMAKE_BUILD_TYPE=$CONFIG ..

echo -e "\n>>> Make..."
make

if [ "$COVERAGE" = "on" ]
then
    echo -e "\n>>> lcov base coverage..."
    lcov --directory . --zerocounters
    lcov --initial --directory . --capture --output-file baseCoverage.info
fi

echo -e "\n>>> Running tests..."
./test

# Generate test coverage report
if [ "$COVERAGE" = "on" ]
then
    echo -e "\n>>> lcov generating report..."
    lcov --directory . --capture --output-file coverage.info

    echo -e "\n>>> lcov merging base with test data..."
    lcov --add-tracefile baseCoverage.info --add-tracefile coverage.info --output-file coverage.info

    echo -e "\n>>> lcov removing some unnecessarily covered files..."
    lcov --remove coverage.info 'src/Main.cpp' 'test/*' 'ext/*' '/usr/*' --output-file coverage.info

    echo -e "\n>>> lcov generating html..."
    genhtml coverage.info --output-directory $COVERAGE_DIR/html

    rm baseCoverage.info
    mv coverage.info $COVERAGE_DIR/coverage.info
fi

cd ..
