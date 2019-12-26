#pragma once

#include "grid.h"

namespace conlife {

struct Position;
class GridObserver;

class Destiny {
public:
    explicit Destiny(Grid grid, GridObserver* observer = nullptr) noexcept;

    auto getNeighbourSize(const Position& position) const noexcept -> std::size_t;
    auto tick() noexcept -> bool;
    auto getGrid() const noexcept -> const Grid&;

private:
    Grid m_grid;
    GridObserver* m_gridObserver;
};

} // namespace conlife
