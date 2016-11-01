#include <set>

#include "gtest/gtest.h"

#include "MapSelection.h"

TEST(TestMapSelection, SelectOneElement) {
    MapSelection selection;

    selection.add(0, 0);

    ASSERT_TRUE(selection.isSelected(0, 0));
}

TEST(TestMapSelection, SelectMultipleElements) {
    MapSelection selection;

    selection.add(0, 0);
    selection.add(1, 0);

    ASSERT_TRUE(selection.isSelected(0, 0));
    ASSERT_TRUE(selection.isSelected(1, 0));
}

TEST(TestMapSelection, RemoveElement) {
    MapSelection selection;

    selection.add(0, 0);
    selection.remove(0, 0);

    ASSERT_TRUE(!selection.isSelected(0, 0));
}

TEST(TestMapSelection, GetSelectedSetWhenOneElement) {
    MapSelection selection;

    selection.add(0, 0);

    std::set<std::tuple<int, int> > expectedSet = {
        std::make_tuple(0, 0)
    };
    ASSERT_EQ(expectedSet, selection.getSelectedSet());
}

TEST(TestMapSelection, GetSelectedSetWhenManyElements) {
    MapSelection selection;

    selection.add(0, 0);
    selection.add(1, 0);

    std::set<std::tuple<int, int> > expectedSet = {
        std::make_tuple(0, 0)
        , std::make_tuple(1, 0)
    };
    ASSERT_EQ(expectedSet, selection.getSelectedSet());
}

TEST(TestMapSelection, GetSelectedSetWhenRemoveElement) {
    MapSelection selection;

    selection.add(0, 0);
    selection.remove(0, 0);

    std::set<std::tuple<int, int> > expectedSet = {};
    ASSERT_EQ(expectedSet, selection.getSelectedSet());
}
