#include <set>

#include "gtest/gtest.h"

#include "MapSelection.h"

TEST(TestMapSelection, SelectOneElement) {
    MapSelection selection;

    selection.add(Coord2(0, 0));

    ASSERT_TRUE(selection.isSelected(Coord2(0, 0)));
}

TEST(TestMapSelection, SelectMultipleElements) {
    MapSelection selection;

    selection.add(Coord2(0, 0));
    selection.add(Coord2(1, 0));

    ASSERT_TRUE(selection.isSelected(Coord2(0, 0)));
    ASSERT_TRUE(selection.isSelected(Coord2(1, 0)));
}

TEST(TestMapSelection, SelectMultipleElements2) {
    MapSelection selection;

    selection.add(Coord2(0, 1));
    selection.add(Coord2(1, 0));

    ASSERT_TRUE(selection.isSelected(Coord2(0, 1)));
    ASSERT_TRUE(selection.isSelected(Coord2(1, 0)));
}

TEST(TestMapSelection, SelectMultipleElements3) {
    MapSelection selection;

    selection.add(Coord2(0, 0));
    selection.add(Coord2(0, 1));
    selection.add(Coord2(1, 0));
    selection.add(Coord2(1, 1));
    selection.add(Coord2(2, 2));

    ASSERT_TRUE(selection.isSelected(Coord2(0, 0)));
    ASSERT_TRUE(selection.isSelected(Coord2(0, 1)));
    ASSERT_TRUE(selection.isSelected(Coord2(1, 0)));
    ASSERT_TRUE(selection.isSelected(Coord2(1, 1)));
    ASSERT_TRUE(selection.isSelected(Coord2(2, 2)));
}

TEST(TestMapSelection, RemoveElement) {
    MapSelection selection;

    selection.add(Coord2(0, 0));
    selection.remove(Coord2(0, 0));

    ASSERT_TRUE(!selection.isSelected(Coord2(0, 0)));
}

TEST(TestMapSelection, GetSelectedSetWhenOneElement) {
    MapSelection selection;

    selection.add(Coord2(0, 0));

    std::set<Coord2> expectedSet = {
        Coord2(0, 0)
    };
    ASSERT_EQ(expectedSet, selection.getSelectedSet());
}

TEST(TestMapSelection, GetSelectedSetWhenManyElements) {
    MapSelection selection;

    selection.add(Coord2(0, 0));
    selection.add(Coord2(1, 0));

    std::set<Coord2> expectedSet = {
        Coord2(0, 0)
        , Coord2(1, 0)
    };
    ASSERT_EQ(expectedSet, selection.getSelectedSet());
}

TEST(TestMapSelection, GetSelectedSetWhenManyElements2) {
    MapSelection selection;

    selection.add(Coord2(0, 1));
    selection.add(Coord2(1, 0));

    std::set<Coord2> expectedSet = {
        Coord2(0, 1)
        , Coord2(1, 0)
    };
    ASSERT_EQ(expectedSet, selection.getSelectedSet());
}

TEST(TestMapSelection, GetSelectedSetWhenManyElements3) {
    MapSelection selection;

    selection.add(Coord2(0, 0));
    selection.add(Coord2(0, 1));
    selection.add(Coord2(1, 0));
    selection.add(Coord2(1, 1));
    selection.add(Coord2(2, 2));

    std::set<Coord2> expectedSet = {
        Coord2(0, 0)
        , Coord2(0, 1)
        , Coord2(1, 0)
        , Coord2(1, 1)
        , Coord2(2, 2)
    };
    ASSERT_EQ(expectedSet, selection.getSelectedSet());
}

TEST(TestMapSelection, GetSelectedSetWhenRemoveElement) {
    MapSelection selection;

    selection.add(Coord2(0, 0));
    selection.remove(Coord2(0, 0));

    std::set<Coord2> expectedSet = {};
    ASSERT_EQ(expectedSet, selection.getSelectedSet());
}

TEST(TestMapSelection, ClearShouldMakeEmpty) {
    MapSelection selection;
    selection.add(Coord2(0, 0));
    selection.add(Coord2(1, 0));

    selection.clear();

    std::set<Coord2> expectedSet;
    ASSERT_EQ(expectedSet, selection.getSelectedSet());
    ASSERT_TRUE(!selection.isSelected(Coord2(0, 0)));
    ASSERT_TRUE(!selection.isSelected(Coord2(1, 0)));
}
