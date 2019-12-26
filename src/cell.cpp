#include "cell.h"

#include <cassert>

namespace conlife {

Cell::Cell() noexcept
    : m_isAlive { false }
    , m_position {}
{
}

Cell::Cell(const Position& position) noexcept
    : m_isAlive { true }
    , m_position { position }
{
}

bool Cell::operator==(const Cell& other) const noexcept
{
    return (m_isAlive == other.m_isAlive) && (m_position == other.m_position);
}

auto Cell::birth(const Position& position) noexcept -> void
{
    assert(!isAlive());

    m_position = position;
    m_isAlive = true;
}

auto Cell::die() noexcept -> void
{
    assert(isAlive());

    m_position = Position {};
    m_isAlive = false;
}

auto Cell::isAlive() const noexcept -> bool
{
    return m_isAlive;
}

auto Cell::getPosition() const noexcept -> Position
{
    return m_position;
}

} // namespace conlife
