#include "destiny.h"
#include "cell.h"

#include <chrono>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <string>
#include <thread>

namespace conlife {

auto getNeighbourSize(Grid& grid, const Cell& cell) noexcept -> std::size_t
{
    std::size_t result = 0U;
    const auto position = cell.getPosition();
    const auto gridWidth = grid.getSize().width;
    const auto gridHeight = grid.getSize().height;
    const auto westNeighbourX = position.x ? position.x - 1U : gridWidth - 1U;
    const auto eastNeighbourX = position.x != gridWidth - 1U ? position.x + 1U : 0U;
    const auto northNeighbourY = position.y ? position.y - 1U : gridHeight - 1U;
    const auto southNeighbourX = position.y != gridHeight - 1U ? position.y + 1U : 0U;

    if (grid.getCell({ westNeighbourX, northNeighbourY }).isAlive())
        ++result;

    if (grid.getCell({ westNeighbourX, position.y }).isAlive())
        ++result;

    if (grid.getCell({ westNeighbourX, southNeighbourX }).isAlive())
        ++result;

    if (grid.getCell({ position.x, northNeighbourY }).isAlive())
        ++result;

    if (grid.getCell({ position.x, southNeighbourX }).isAlive())
        ++result;

    if (grid.getCell({ eastNeighbourX, northNeighbourY }).isAlive())
        ++result;

    if (grid.getCell({ eastNeighbourX, position.y }).isAlive())
        ++result;

    if (grid.getCell({ eastNeighbourX, southNeighbourX }).isAlive())
        ++result;

    return result;
}

Grid Destiny::createGrid(const Grid::Size& size) const
{
    return Grid { size };
}

void Destiny::populate(Grid& grid, const Cell& cell) const noexcept
{
    grid.populate(cell.getPosition());
}

void print(Grid& grid)
{
    std::cout << std::flush;
    system("tput clear");

    const auto size = grid.getSize();

    for (auto y = 0U; y < size.height; ++y) {
        for (auto x = 0U; x < size.width; ++x) {
            auto cell = grid.getCell({ x, y });
            if (cell.isAlive()) {
                std::cout << "\033[1;31m▮ \033[0m";
            } else {
                std::cout << ". ";
            }
        }
        std::cout << std::endl;
    }

    using namespace std::chrono_literals;
    std::this_thread::sleep_for(100ms);
}

void Destiny::tick(Grid& grid) noexcept
{
    print(grid);

    auto gridNext = grid;

    const auto size = grid.getSize();


    for (auto y = 0U; y < size.height; ++y) {
        for (auto x = 0U; x < size.width; ++x) {
            auto cell = grid.getCell({ x, y });
            const auto neighbourSize = getNeighbourSize(grid, conlife::Cell { { x, y } });
            if (cell.isAlive()) {
                if (neighbourSize < 2U)
                    gridNext.unpopulate({ x, y });

                if (neighbourSize > 3U)
                    gridNext.unpopulate({ x, y });
            } else {
                if (neighbourSize == 3U)
                    gridNext.populate({ x, y });
            }
        }
    }

    grid = gridNext;
}

} // namespace conlife
