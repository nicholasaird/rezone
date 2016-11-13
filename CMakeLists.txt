cmake_minimum_required (VERSION 2.8)
project (rezone)

# Set up c++11
include (CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG ("-std=c++11" COMPILER_SUPPORTS_CXX11)
if (COMPILER_SUPPORTS_CXX11)
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
else ()
    message (ERROR "The compiler ${CMAKE_CXX_COMPILER} has no c++11 support. Please use another compiler.")
endif ()

# Set up code coverage
set (USE_COVERAGE "$ENV{COVERAGE}")
if (USE_COVERAGE)
    message (STATUS "Adding code coverage.")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
endif ()

# Threading required for gtest
find_package (Threads REQUIRED)

# Gtest
enable_testing ()
add_subdirectory (ext/googletest)

# Gtest printer
add_subdirectory (ext/googletestCustomOutput)

# Docopt
add_subdirectory (ext/docopt.cpp)
add_library (docoptLib ALIAS docopt_s)

# MainLib
set (mainSrc
    src/main/command/SelectCommand.cpp
    src/main/command/CommandUtils.cpp
    src/main/command/UnselectCommand.cpp
    src/main/command/Command.cpp
    src/main/command/UnfoundArgumentException.cpp
    src/main/command/WrongTypeArgumentException.cpp
    src/main/command/GiveCommand.cpp
    src/main/command/QuitCommand.cpp
    src/main/command/CommandPrompt.cpp
    src/main/command/MapCommand.cpp
    src/main/command/CommandArguments.cpp
    src/main/graphics/ImageException.cpp
    src/main/graphics/TextImage.cpp
    src/main/NonZeroResourceMap.cpp
    src/main/Map.cpp
    src/main/MapSelection.cpp
    src/main/math/Coord2.cpp
    src/main/math/Dim2.cpp
    src/main/math/DimException.cpp
    src/main/math/CoordException.cpp
    src/main/Quota.cpp
    src/main/ResourceException.cpp
    src/main/Stock.cpp
    src/main/Utils.cpp
    src/main/Zone.cpp
)
add_library (mainLib STATIC ${mainSrc})
target_include_directories (mainLib PUBLIC "src/main")
target_link_libraries (mainLib docoptLib)

# Main
add_executable (main "src/Main.cpp")
target_link_libraries (main mainLib docoptLib)
set_property (TARGET main PROPERTY OUTPUT_NAME rezone)

# MainLib tests
set (testMainSrc
    test/docopt/TestDocopt.cpp
    test/language/TestMap.cpp
    test/main/command/TestCommandArguments.cpp
    test/main/math/TestCoord2.cpp
    test/main/math/TestDim2.cpp
    test/main/Textgraphics/TestTextImage.cpp
    test/main/TestGrid.cpp
    test/main/TestMapSelection.cpp
    test/main/TestNonZeroResourceMap.cpp
    test/main/TestQuota.cpp
    test/main/TestStock/TestStockTimesEqual.cpp
    test/main/TestStock/TestStockPlus.cpp
    test/main/TestStock/TestStockMinusEqual.cpp
    test/main/TestStock/TestStockSum.cpp
    test/main/TestStock/TestStockPlusEqual.cpp
    test/main/TestStock/TestStockEquality.cpp
    test/main/TestStock/TestStockSupersetOf.cpp
    test/main/TestStock/TestStockTimes.cpp
    test/main/TestStock/TestStockUnaryMinus.cpp
    test/main/TestStock/TestStockGetSet.cpp
    test/main/TestStock/TestStockDiv.cpp
    test/main/TestStock/TestStockMinus.cpp
    test/main/TestStock/TestStockTimesItContains.cpp
    test/main/TestStock/TestStockIterator.cpp
    test/main/TestStock/TestStockSubsetOf.cpp
    test/main/TestStock/TestStockDivEqual.cpp
    test/main/TestStock/TestStockInequality.cpp
    test/main/TestStockPair.cpp
    test/main/TestUtils.cpp
    test/main/TestZone.cpp
)
file (GLOB_RECURSE testMainSrc "test/*.cpp")
add_executable (testMainLib ${testMainSrc})
target_link_libraries (testMainLib mainLib gtest gmock pthread gprintGmockMainLib)
add_test ("testAll" testMainLib)  # so that ctest finds the tests
