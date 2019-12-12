#pragma once

#include "coordinates.h"

namespace conlife {

class Cell {
public:
    enum class State {
        Dead,
        Alive
    };

    Cell() noexcept;
    explicit Cell(const Coordinates& position) noexcept;

    bool operator==(const Cell& other) const noexcept;

    auto die() noexcept -> void;
    auto birth(const Coordinates& position) noexcept -> void;
    auto getState() const noexcept -> State;
    auto isAlive() const noexcept -> bool;
    auto isDead() const noexcept -> bool;
    auto getPosition() const noexcept -> Coordinates;
    auto setPosition(const Coordinates& position) noexcept -> void;

private:
    State m_state;
    Coordinates m_position;
};

} // namespace conlife
