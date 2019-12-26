#include "destiny.h"
#include "cell.h"
#include "position.h"

#include <chrono>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <string>
#include <thread>

namespace conlife {

auto print(Grid& grid) -> void
{
    std::system("clear");

    const auto size = grid.getSize();

    for (auto y = 0U; y < size.height; ++y) {
        for (auto x = 0U; x < size.width; ++x) {
            auto cell = grid.getCell({ x, y });
            if (cell.isAlive()) {
                using namespace std::string_literals;
                const auto reset = "\033[0m"s;
                const auto red = "\033[1m\033[41m"s;
                const auto square = "  ";
                std::cout << red << square << reset;
            } else {
                std::cout << ". ";
            }
        }
        std::cout << '\n';
    }

    using namespace std::chrono_literals;
    std::this_thread::sleep_for(80ms);
}

Destiny::Destiny(Grid grid) noexcept
    : m_grid { std::move(grid) }
{
}

auto Destiny::getNeighbourSize(const Position& position) const noexcept -> std::size_t
{
    std::size_t result = 0U;
    const auto gridWidth = m_grid.getSize().width;
    const auto gridHeight = m_grid.getSize().height;
    const auto westNeighbourX = position.x ? (position.x - 1U) : (gridWidth - 1U);

    if (m_grid.getCell({ westNeighbourX, position.y }).isAlive())
        ++result;

    const auto northNeighbourY = position.y ? (position.y - 1U) : (gridHeight - 1U);

    if (m_grid.getCell({ position.x, northNeighbourY }).isAlive())
        ++result;

    if (m_grid.getCell({ westNeighbourX, northNeighbourY }).isAlive())
        ++result;

    const auto southNeighbourX = position.y != (gridHeight - 1U) ? (position.y + 1U) : 0U;

    if (m_grid.getCell({ position.x, southNeighbourX }).isAlive())
        ++result;

    if (m_grid.getCell({ westNeighbourX, southNeighbourX }).isAlive())
        ++result;

    const auto eastNeighbourX = position.x != (gridWidth - 1U) ? (position.x + 1U) : 0U;

    if (m_grid.getCell({ eastNeighbourX, position.y }).isAlive())
        ++result;

    if (m_grid.getCell({ eastNeighbourX, northNeighbourY }).isAlive())
        ++result;

    if (m_grid.getCell({ eastNeighbourX, southNeighbourX }).isAlive())
        ++result;

    return result;
}

auto Destiny::tick() noexcept -> bool
{
    print(m_grid);

    auto nextGrid = m_grid;

    for (auto y = 0U; y < nextGrid.getSize().height; ++y) {
        for (auto x = 0U; x < nextGrid.getSize().width; ++x) {
            const auto position = Position { x, y };
            const auto neighbourSize = getNeighbourSize(position);
            if (nextGrid.getCell(position).isAlive()) {
                if ((neighbourSize < 2U) || (neighbourSize > 3U))
                    nextGrid.unpopulate(position);
            } else {
                if (neighbourSize == 3U)
                    nextGrid.populate(position);
            }
        }
    }

    if (m_grid == nextGrid)
        return false;

    m_grid = nextGrid;

    return true;
}

auto Destiny::getGrid() const noexcept -> const Grid&
{
    return m_grid;
}

} // namespace conlife
