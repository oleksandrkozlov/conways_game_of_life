#include "destiny.h"
#include "grid.h"

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv) noexcept
{

    auto destiny = conlife::Destiny {};

    auto grid = destiny.createGrid({ 20U, 20U });
    destiny.populate(grid, conlife::Cell { { 1U, 0U } });
    destiny.populate(grid, conlife::Cell { { 2U, 1U } });
    destiny.populate(grid, conlife::Cell { { 0U, 2U } });
    destiny.populate(grid, conlife::Cell { { 1U, 2U } });
    destiny.populate(grid, conlife::Cell { { 2U, 2U } });

    while (true)
        destiny.tick(grid);

    return 0;
}
