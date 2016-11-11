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
    src/main/NonZeroResourceMap.cpp
    src/main/Map.cpp
    src/main/ResourceException.cpp
    src/main/Utils.cpp
    src/main/Zone.cpp
    src/main/InvalidCoordinateException.cpp
    src/main/MapSelection.cpp
    src/main/Quota.cpp
    src/main/Command/SelectCommand.cpp
    src/main/Command/CommandUtils.cpp
    src/main/Command/UnselectCommand.cpp
    src/main/Command/Command.cpp
    src/main/Command/UnfoundArgumentException.cpp
    src/main/Command/WrongTypeArgumentException.cpp
    src/main/Command/GiveCommand.cpp
    src/main/Command/QuitCommand.cpp
    src/main/Command/CommandPrompt.cpp
    src/main/Command/MapCommand.cpp
    src/main/Command/CommandArguments.cpp
    src/main/Stock.cpp
    src/main/Coord2.cpp
    src/main/Graphics/ImageException.cpp
    src/main/Graphics/TextImage.cpp)
add_library (mainLib STATIC ${mainSrc})
target_include_directories (mainLib PUBLIC "src/main")
target_link_libraries (mainLib docoptLib)

# Main
add_executable (main "src/Main.cpp")
target_link_libraries (main mainLib docoptLib)
set_property (TARGET main PROPERTY OUTPUT_NAME rezone)

# MainLib tests
set (testMainSrc
    test/main/TestCommand/TestCommandArguments.cpp
    test/main/TestStockPair.cpp
    test/main/TestMapSelection.cpp
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
    test/main/TextGraphics/TestTextImage.cpp
    test/main/TestCoord2.cpp
    test/main/TestNonZeroResourceMap.cpp
    test/main/TestUtils.cpp
    test/main/TestQuota.cpp
    test/main/TestGrid.cpp
    test/main/TestZone.cpp
    test/docopt/TestDocopt.cpp
    test/language/TestMap.cpp)
file (GLOB_RECURSE testMainSrc "test/*.cpp")
add_executable (testMainLib ${testMainSrc})
target_link_libraries (testMainLib mainLib gtest gmock pthread gprintGmockMainLib)
add_test ("testAll" testMainLib)  # so that ctest finds the tests
