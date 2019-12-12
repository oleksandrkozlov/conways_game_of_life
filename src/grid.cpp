#include "grid.h"

#include <cassert>
#include <iostream>

namespace conlife {

Grid::Grid(const Grid::Size& size)
    : m_size { size }
    , m_grid { Row(size.height, Column(size.width)) }
{
}

bool Grid::operator==(const Grid& other) const noexcept
{
    return m_grid == other.m_grid;
}

auto Grid::getSize() const noexcept -> Grid::Size
{
    return m_size;
}

void Grid::populate(const Coordinates& position) noexcept
{
    assert(position.y < std::size(m_grid));
    assert(position.x < std::size(m_grid.at(position.y)));

    m_grid.at(position.y).at(position.x).birth(position);
}

void Grid::unpopulate(const Coordinates& position) noexcept
{
    assert(position.y < std::size(m_grid));
    assert(position.x < std::size(m_grid.at(position.y)));

    m_grid.at(position.y).at(position.x).die();
}

Cell Grid::getCell(const Coordinates& position) const noexcept
{
    assert(position.y < std::size(m_grid));
    assert(position.x < std::size(m_grid.at(position.y)));

    return m_grid.at(position.y).at(position.x);
}

} // namespace conlife
