#include <gtest/gtest.h>

#include "destiny.h"
#include "position.h"

TEST(Core, getNeighbourSizeZero)
{
    auto position = conlife::Position { 0U, 0U };
    auto grid = conlife::Grid { { 3U, 3U } };
    grid.populate(position);
    auto destiny = conlife::Destiny { grid };
    ASSERT_EQ(destiny.getNeighbourSize(position), 0U);

    position = conlife::Position { 1U, 0U };
    grid = conlife::Grid { { 3U, 3U } };
    grid.populate(position);
    destiny = conlife::Destiny { grid };
    ASSERT_EQ(destiny.getNeighbourSize(position), 0U);

    position = conlife::Position { 2U, 0U };
    grid = conlife::Grid { { 3U, 3U } };
    grid.populate(position);
    destiny = conlife::Destiny { grid };
    ASSERT_EQ(destiny.getNeighbourSize(position), 0U);

    position = conlife::Position { 0U, 1U };
    grid = conlife::Grid { { 3U, 3U } };
    grid.populate(position);
    destiny = conlife::Destiny { grid };
    ASSERT_EQ(destiny.getNeighbourSize(position), 0U);

    position = conlife::Position { 1U, 1U };
    grid = conlife::Grid { { 3U, 3U } };
    grid.populate(position);
    destiny = conlife::Destiny { grid };
    ASSERT_EQ(destiny.getNeighbourSize(position), 0U);

    position = conlife::Position { 2U, 1U };
    grid = conlife::Grid { { 3U, 3U } };
    grid.populate(position);
    destiny = conlife::Destiny { grid };
    ASSERT_EQ(destiny.getNeighbourSize(position), 0U);

    position = conlife::Position { 0U, 2U };
    grid = conlife::Grid { { 3U, 3U } };
    grid.populate(position);
    destiny = conlife::Destiny { grid };
    ASSERT_EQ(destiny.getNeighbourSize(position), 0U);

    position = conlife::Position { 1U, 2U };
    grid = conlife::Grid { { 3U, 3U } };
    grid.populate(position);
    destiny = conlife::Destiny { grid };
    ASSERT_EQ(destiny.getNeighbourSize(position), 0U);

    position = conlife::Position { 2U, 2U };
    grid = conlife::Grid { { 3U, 3U } };
    grid.populate(position);
    destiny = conlife::Destiny { grid };
    ASSERT_EQ(destiny.getNeighbourSize(position), 0U);
}

TEST(Core, getNeighbourSizeEight)
{
    auto grid = conlife::Grid { { 3U, 3U } };

    grid.populate({ 0U, 0U });
    grid.populate({ 1U, 0U });
    grid.populate({ 2U, 0U });
    grid.populate({ 0U, 1U });
    grid.populate({ 2U, 1U });
    grid.populate({ 0U, 2U });
    grid.populate({ 1U, 2U });
    grid.populate({ 2U, 2U });

    auto destiny = conlife::Destiny { grid };
    ASSERT_EQ(destiny.getNeighbourSize(conlife::Position { 1U, 1U }), 8U);
}

TEST(Core, getNeighbourSizeThree)
{
    auto grid = conlife::Grid { { 5U, 5U } };
    grid.populate({ 2U, 1U });
    grid.populate({ 2U, 2U });
    grid.populate({ 2U, 3U });

    auto destiny = conlife::Destiny { grid };
    ASSERT_EQ(destiny.getNeighbourSize(conlife::Position { 1U, 2U }), 3U);
    ASSERT_EQ(destiny.getNeighbourSize(conlife::Position { 3U, 2U }), 3U);
}
