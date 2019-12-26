#include "grid.h"
#include "position.h"

#include <cassert>

namespace conlife {

Grid::Grid(Grid::Size size)
    : m_size { std::move(size) }
    , m_grid { Row(size.height, Column(size.width)) }
{
}

auto Grid::operator==(const Grid& other) const noexcept -> bool
{
    return m_grid == other.m_grid;
}

auto Grid::getSize() const noexcept -> Grid::Size
{
    return m_size;
}

auto Grid::populate(const Position& position) noexcept -> void
{
    assert(position.y < std::size(m_grid));
    assert(position.x < std::size(m_grid.at(position.y)));

    m_grid.at(position.y).at(position.x).birth(position);
}

auto Grid::unpopulate(const Position& position) noexcept -> void
{
    assert(position.y < std::size(m_grid));
    assert(position.x < std::size(m_grid.at(position.y)));

    m_grid.at(position.y).at(position.x).die();
}

auto Grid::getCell(const Position& position) const noexcept -> Cell
{
    assert(position.y < std::size(m_grid));
    assert(position.x < std::size(m_grid.at(position.y)));

    return m_grid.at(position.y).at(position.x);
}

} // namespace conlife
