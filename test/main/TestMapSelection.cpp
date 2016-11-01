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
