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
      'src/main/NonZeroResourceMap.cpp'
    , 'src/main/Map.cpp'
    , 'src/main/ResourceException.cpp'
    , 'src/main/Utils.cpp'
    , 'src/main/Zone.cpp'
    , 'src/main/InvalidCoordinateException.cpp'
    , 'src/main/MapSelection.cpp'
    , 'src/main/Quota.cpp'
    , 'src/main/Command/SelectCommand.cpp'
    , 'src/main/Command/CommandUtils.cpp'
    , 'src/main/Command/UnselectCommand.cpp'
    , 'src/main/Command/Command.cpp'
    , 'src/main/Command/UnfoundArgumentException.cpp'
    , 'src/main/Command/WrongTypeArgumentException.cpp'
    , 'src/main/Command/GiveCommand.cpp'
    , 'src/main/Command/QuitCommand.cpp'
    , 'src/main/Command/CommandPrompt.cpp'
    , 'src/main/Command/MapCommand.cpp'
    , 'src/main/Command/CommandArguments.cpp'
    , 'src/main/Stock.cpp'
    , 'src/main/Coord2.cpp'
    , 'src/main/Graphics/ImageException.cpp'
    , 'src/main/Graphics/TextImage.cpp'
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
gtestSrc = ['ext/googletest/googletest/src/gtest-all.cc']
gtestInc = include_directories(['ext/googletest/googletest/include', 'ext/googletest/googletest'])
gtestLib = static_library(
	'gtestLib'
	, sources : gtestSrc
	, include_directories : gtestInc
	, dependencies : threadDep
)
gtestLibDep = declare_dependency(
	link_with : gtestLib
	, include_directories : gtestInc
	, dependencies : threadDep
)

gtestMainSrc = ['ext/googletest/googletest/src/gtest_main.cc']
gtestMainLib = static_library(
	'gtestMainLib'
	, sources : gtestSrc
	, dependencies : gtestLibDep
)
gtestMainLibDep = declare_dependency(
	link_with : gtestMainLib
	, dependencies : gtestLibDep
)

# gmock
gmockSrc = ['ext/googletest/googlemock/src/gmock-all.cc']
gmockInc = include_directories(['ext/googletest/googlemock/include', 'ext/googletest/googlemock'])
gmockLib = static_library(
	'gmockLib'
	, sources : gmockSrc
	, include_directories : gmockInc
	, dependencies : gtestLibDep
)
gmockLibDep = declare_dependency(
	link_with : gmockLib
	, include_directories : gmockInc
	, dependencies : gtestLibDep
)

gmockMainSrc = ['ext/googletest/googlemock/src/gmock_main.cc']
gmockMainLib = static_library(
	'gmockMainLib'
	, sources : gmockSrc
	, dependencies : [gmockLibDep, gtestLibDep]
)
gmockMainLibDep = declare_dependency(
	link_with : gtestMainLib
	, dependencies : [gmockLibDep, gtestLibDep]
)

# gprint (for better gtest output)
subdir('ext/googletestCustomOutput')
# Produces the following libs (and their dependencies):
#   gprintLib
#   gprintGtestMainLib
#   gprintGmockMainLib

filesTestMain = [
   'test/main/TestCommand/TestCommandArguments.cpp'
   , 'test/main/TestStockPair.cpp'
   , 'test/main/TestMapSelection.cpp'
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
   , 'test/main/TextGraphics/TestTextImage.cpp'
   , 'test/main/TestCoord2.cpp'
   , 'test/main/TestNonZeroResourceMap.cpp'
   , 'test/main/TestUtils.cpp'
   , 'test/main/TestQuota.cpp'
   , 'test/main/TestGrid.cpp'
   , 'test/main/TestZone.cpp'
   , 'test/docopt/TestDocopt.cpp'
   , 'test/language/TestMap.cpp'
]

# Main test
mainTestExe = executable(
	'mainTest'
	, sources : filesTestMain
	, dependencies : [mainLibDep, gtestLibDep, gprintGtestMainLibDep]
)
