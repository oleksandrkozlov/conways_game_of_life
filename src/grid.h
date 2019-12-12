#pragma once

#include <cstddef>
#include <vector>

#include "cell.h"
#include "coordinates.h"

namespace conlife {

class Grid
{
    friend class Destiny;

public:
private:
    using Column = std::vector<Cell>;
    using Row = std::vector<Column>;

public:
    struct Size {
        std::size_t width = 0U;
        std::size_t height = 0U;
    };

private:
    explicit Grid(const Size& size);

    bool operator==(const Grid& other) const noexcept;

public:
    auto getSize() const noexcept -> Size;
    void populate(const Coordinates& position) noexcept;
    void unpopulate(const Coordinates& position) noexcept;
    Cell getCell(const Coordinates& position) const noexcept;

private:
    Size m_size;
    Row m_grid;
};

} // namespace conlife
