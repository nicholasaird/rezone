#include <memory>  // shared pointer
#include <set>
#include <tuple>

#include "gtest/gtest.h"

#include "Command/SelectCommand.h"
#include "Map.h"
#include "InvalidCoordinateException.h"

void selectPoint(SelectCommand& selectCommand, int x, int y) {
    CommandArguments args;
    args.add("x", x);
    args.add("y", y);
    selectCommand.execute(args);
}

TEST(TestSelectCommand, SelectAValidElement) {
    std::shared_ptr<Map> map = std::make_shared<Map>(1, 1);
    std::shared_ptr<MapSelection> selected = std::make_shared<MapSelection>();
    SelectCommand selectCommand(map, selected);

    selectPoint(selectCommand, 0, 0);

    std::set<std::tuple<int, int> > expectedSelection = {
        std::make_tuple(0, 0)
    };
    ASSERT_EQ(expectedSelection, selected->getSelectedSet());
    ASSERT_TRUE(selected->isSelected(0, 0));
}
