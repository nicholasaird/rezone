project('rezone', 'cpp')
add_global_arguments('-std=c++11', language : 'cpp')

# Docopt static library
filesSrcDocopt = [
	'ext/docopt.cpp/docopt.cpp'
]
filesIncDocopt = [
	'ext/docopt.cpp/docopt.h'
	, 'ext/docopt.cpp/docopt_private.h'
	, 'ext/docopt.cpp/docopt_util.h'
	, 'ext/docopt.cpp/docopt_value.h'
]
docoptLibInc = include_directories('ext/docopt.cpp')
docoptLib = static_library(
    'docoptLib'
	, sources : filesSrcDocopt
	, include_directories : docoptLibInc
)
docoptLibDep = declare_dependency(
	link_with : docoptLib
	, include_directories : docoptLibInc
)

# Main static library
filesSrcMain = [
	'src/main/command/SelectCommand.cpp'
	, 'src/main/command/CommandUtils.cpp'
	, 'src/main/command/UnselectCommand.cpp'
	, 'src/main/command/Command.cpp'
	, 'src/main/command/UnfoundArgumentException.cpp'
	, 'src/main/command/WrongTypeArgumentException.cpp'
	, 'src/main/command/GiveCommand.cpp'
	, 'src/main/command/QuitCommand.cpp'
	, 'src/main/command/CommandPrompt.cpp'
	, 'src/main/command/MapCommand.cpp'
	, 'src/main/command/CommandArguments.cpp'
	, 'src/main/graphics/ImageException.cpp'
	, 'src/main/graphics/TextImage.cpp'
	, 'src/main/MapSelection.cpp'
	, 'src/main/math/Coord2.cpp'
	, 'src/main/math/Dim2.cpp'
	, 'src/main/math/DimException.cpp'
	, 'src/main/math/InvalidCoordinateException.cpp'
    , 'src/main/NonZeroResourceMap.cpp'
    , 'src/main/Map.cpp'
	, 'src/main/Quota.cpp'
    , 'src/main/ResourceException.cpp'
	, 'src/main/Stock.cpp'
    , 'src/main/Utils.cpp'
    , 'src/main/Zone.cpp'
]

mainLibInc = include_directories('src/main')
mainLib = static_library(
    'mainLib'
    , sources : filesSrcMain
    , include_directories : mainLibInc
	, dependencies : docoptLibDep
)
mainLibDep = declare_dependency(
	link_with : mainLib
	, include_directories : mainLibInc
	, dependencies : docoptLibDep
)

mainExe = executable(
    'rezone'
    , sources : 'src/Main.cpp'
	, dependencies : mainLibDep
)

threadDep = dependency(
    'threads'
)

# gtest
gtestInc = include_directories(['ext/googletest/googletest/include', 'ext/googletest/googletest'])
gtestLib = static_library(
	'gtestLib'
	, sources : 'ext/googletest/googletest/src/gtest-all.cc'
	, include_directories : gtestInc
	, dependencies : threadDep
)
gtestLibDep = declare_dependency(
	link_with : gtestLib
	, include_directories : gtestInc
	, dependencies : threadDep
)

gtestMainLib = static_library(
	'gtestMainLib'
	, sources : 'ext/googletest/googletest/src/gtest_main.cc'
	, dependencies : gtestLibDep
)
gtestMainLibDep = declare_dependency(
	link_with : gtestMainLib
	, dependencies : gtestLibDep
)

# gmock
gmockInc = include_directories(['ext/googletest/googlemock/include', 'ext/googletest/googlemock'])
gmockLib = static_library(
	'gmockLib'
	, sources : 'ext/googletest/googlemock/src/gmock-all.cc'
	, include_directories : gmockInc
	, dependencies : gtestLibDep
)
gmockLibDep = declare_dependency(
	link_with : gmockLib
	, include_directories : gmockInc
	, dependencies : gtestLibDep
)

gmockMainLib = static_library(
	'gmockMainLib'
	, sources : 'ext/googletest/googlemock/src/gmock_main.cc'
	, dependencies : [gmockLibDep, gtestLibDep]
)
gmockMainLibDep = declare_dependency(
	link_with : gmockMainLib
	, dependencies : [gmockLibDep, gtestLibDep]
)

# gprint (for better gtest output)
subdir('ext/googletestCustomOutput')
# Produces the following libs (and their dependencies):
#   gprintLib
#   gprintGtestMainLib
#   gprintGmockMainLib

filesTestMain = [
   'test/docopt/TestDocopt.cpp'
   , 'test/language/TestMap.cpp'
   , 'test/main/command/TestCommandArguments.cpp'
   , 'test/main/graphics/TestTextImage.cpp'
   , 'test/main/math/TestCoord2.cpp'
   , 'test/main/math/TestDim2.cpp'
   , 'test/main/TestGrid.cpp'
   , 'test/main/TestMapSelection.cpp'
   , 'test/main/TestNonZeroResourceMap.cpp'
   , 'test/main/TestStockPair.cpp'
   , 'test/main/TestStock/TestStockTimesEqual.cpp'
   , 'test/main/TestStock/TestStockPlus.cpp'
   , 'test/main/TestStock/TestStockMinusEqual.cpp'
   , 'test/main/TestStock/TestStockSum.cpp'
   , 'test/main/TestStock/TestStockPlusEqual.cpp'
   , 'test/main/TestStock/TestStockEquality.cpp'
   , 'test/main/TestStock/TestStockSupersetOf.cpp'
   , 'test/main/TestStock/TestStockTimes.cpp'
   , 'test/main/TestStock/TestStockUnaryMinus.cpp'
   , 'test/main/TestStock/TestStockGetSet.cpp'
   , 'test/main/TestStock/TestStockDiv.cpp'
   , 'test/main/TestStock/TestStockMinus.cpp'
   , 'test/main/TestStock/TestStockTimesItContains.cpp'
   , 'test/main/TestStock/TestStockIterator.cpp'
   , 'test/main/TestStock/TestStockSubsetOf.cpp'
   , 'test/main/TestStock/TestStockDivEqual.cpp'
   , 'test/main/TestStock/TestStockInequality.cpp'
   , 'test/main/TestUtils.cpp'
   , 'test/main/TestQuota.cpp'
   , 'test/main/TestZone.cpp'
]

# Main test
mainTestExe = executable(
	'mainTest'
	, sources : filesTestMain
	, dependencies : [mainLibDep, gtestLibDep, gprintGtestMainLibDep]
)
