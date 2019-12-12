#pragma once

#include "cell.h"
#include "grid.h"

namespace conlife {

auto getNeighbourSize(Grid& grid, const Cell& cell) noexcept -> std::size_t;

class Destiny
{
public:
    Grid createGrid(const Grid::Size& size) const;
    void populate(Grid& grid, const Cell& position) const noexcept;

    auto tick(Grid& grid) noexcept -> bool;
};

} // namespace conlife
