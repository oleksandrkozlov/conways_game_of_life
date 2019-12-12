#include "destiny.h"
#include "grid.h"

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv) noexcept
{
    auto destiny = conlife::Destiny {};

    // glider
    //auto grid = destiny.createGrid({ 100U, 60U });
    //destiny.populate(grid, conlife::Cell { { 1U, 0U } });
    //destiny.populate(grid, conlife::Cell { { 2U, 1U } });
    //destiny.populate(grid, conlife::Cell { { 0U, 2U } });
    //destiny.populate(grid, conlife::Cell { { 1U, 2U } });
    //destiny.populate(grid, conlife::Cell { { 2U, 2U } });

    // diehard
    auto grid = destiny.createGrid({ 23U, 23U });
    destiny.populate(grid, conlife::Cell { { 8U, 5U } });
    destiny.populate(grid, conlife::Cell { { 9U, 5U } });
    destiny.populate(grid, conlife::Cell { { 9U, 6U } });
    destiny.populate(grid, conlife::Cell { { 14U, 4U } });
    destiny.populate(grid, conlife::Cell { { 13U, 6U } });
    destiny.populate(grid, conlife::Cell { { 14U, 6U } });
    destiny.populate(grid, conlife::Cell { { 15U, 6U } });

    while (destiny.tick(grid))
        ;

    return 0;
}
