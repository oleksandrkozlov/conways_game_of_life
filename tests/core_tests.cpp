#include <gtest/gtest.h>

#include "cell.h"
#include "destiny.h"
#include "grid.h"

TEST(Core, getNeighbourSizeZero)
{
    const auto destiny = conlife::Destiny {};

    auto grid = destiny.createGrid({ 3U, 3U });
    auto cell = conlife::Cell { { 0U, 0U } };
    destiny.populate(grid, cell);
    ASSERT_EQ(getNeighbourSize(grid, cell), 0U);

    grid = destiny.createGrid({ 3U, 3U });
    cell = conlife::Cell { { 1U, 0U } };
    destiny.populate(grid, cell);
    ASSERT_EQ(getNeighbourSize(grid, cell), 0U);

    grid = destiny.createGrid({ 3U, 3U });
    cell = conlife::Cell { { 2U, 0U } };
    destiny.populate(grid, cell);
    ASSERT_EQ(getNeighbourSize(grid, cell), 0U);

    grid = destiny.createGrid({ 3U, 3U });
    cell = conlife::Cell { { 0U, 1U } };
    destiny.populate(grid, cell);
    ASSERT_EQ(getNeighbourSize(grid, cell), 0U);

    grid = destiny.createGrid({ 3U, 3U });
    cell = conlife::Cell { { 1U, 1U } };
    destiny.populate(grid, cell);
    ASSERT_EQ(getNeighbourSize(grid, cell), 0U);

    grid = destiny.createGrid({ 3U, 3U });
    cell = conlife::Cell { { 2U, 1U } };
    destiny.populate(grid, cell);
    ASSERT_EQ(getNeighbourSize(grid, cell), 0U);

    grid = destiny.createGrid({ 3U, 3U });
    cell = conlife::Cell { { 0U, 2U } };
    destiny.populate(grid, cell);
    ASSERT_EQ(getNeighbourSize(grid, cell), 0U);

    grid = destiny.createGrid({ 3U, 3U });
    cell = conlife::Cell { { 1U, 2U } };
    destiny.populate(grid, cell);
    ASSERT_EQ(getNeighbourSize(grid, cell), 0U);

    grid = destiny.createGrid({ 3U, 3U });
    cell = conlife::Cell { { 2U, 2U } };
    destiny.populate(grid, cell);
    ASSERT_EQ(getNeighbourSize(grid, cell), 0U);
}

TEST(Core, getNeighbourSizeEight)
{
    const auto destiny = conlife::Destiny {};
    auto grid = destiny.createGrid({ 3U, 3U });

    destiny.populate(grid, conlife::Cell { { 0U, 0U } });
    destiny.populate(grid, conlife::Cell { { 1U, 0U } });
    destiny.populate(grid, conlife::Cell { { 2U, 0U } });
    destiny.populate(grid, conlife::Cell { { 0U, 1U } });
    destiny.populate(grid, conlife::Cell { { 2U, 1U } });
    destiny.populate(grid, conlife::Cell { { 0U, 2U } });
    destiny.populate(grid, conlife::Cell { { 1U, 2U } });
    destiny.populate(grid, conlife::Cell { { 2U, 2U } });

    ASSERT_EQ(getNeighbourSize(grid, conlife::Cell { { 1U, 1U } }), 8U);
}

TEST(Core, getNeighbourSizeThree)
{
    auto destiny = conlife::Destiny {};

    auto grid = destiny.createGrid({ 5U, 5U });
    destiny.populate(grid, conlife::Cell { { 2U, 1U } });
    destiny.populate(grid, conlife::Cell { { 2U, 2U } });
    destiny.populate(grid, conlife::Cell { { 2U, 3U } });

    ASSERT_EQ(getNeighbourSize(grid, conlife::Cell { { 1U, 2U } }), 3U);
    ASSERT_EQ(getNeighbourSize(grid, conlife::Cell { { 3U, 2U } }), 3U);
}
