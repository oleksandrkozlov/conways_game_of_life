#pragma once

#include <cstddef>
#include <vector>

#include "cell.h"

namespace conlife {

struct Position;

class Grid
{
private:
    using Column = std::vector<Cell>;
    using Row = std::vector<Column>;

public:
    struct Size {
        std::size_t width = 0U;
        std::size_t height = 0U;
    };

    explicit Grid(Size size);

    auto operator==(const Grid& other) const noexcept -> bool;

    auto getSize() const noexcept -> Size;
    auto populate(const Position& position) noexcept -> void;
    auto unpopulate(const Position& position) noexcept -> void;
    auto getCell(const Position& position) const noexcept -> Cell;

private:
    Size m_size;
    Row m_grid;
};

} // namespace conlife
