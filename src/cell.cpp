#include "cell.h"

#include <cassert>

namespace conlife {

Cell::Cell() noexcept
    : m_state { State::Dead }
    , m_position {}
{
}

Cell::Cell(const Coordinates& position) noexcept
    : m_state { State::Alive }
    , m_position { position }
{
}

bool Cell::operator==(const Cell& other) const noexcept
{
    return (m_state == other.m_state) && (m_position == other.m_position);
}

auto Cell::birth(const Coordinates& position) noexcept -> void
{
    assert(isDead());

    m_position = position;
    m_state = State::Alive;
}

auto Cell::die() noexcept -> void
{
    assert(isAlive());

    m_state = State::Dead;
}

auto Cell::getState() const noexcept -> Cell::State
{
    return m_state;
}

auto Cell::isAlive() const noexcept -> bool
{
    return m_state == State::Alive;
}

auto Cell::isDead() const noexcept -> bool
{
    return m_state == State::Dead;
}

auto Cell::getPosition() const noexcept -> Coordinates
{
    return m_position;
}

auto Cell::setPosition(const Coordinates& position) noexcept -> void
{
    m_position = position;
}

} // namespace conlife
