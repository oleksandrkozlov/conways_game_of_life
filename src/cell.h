#pragma once

#include "position.h"

namespace conlife {

class Cell {
public:
    Cell() noexcept;
    explicit Cell(const Position& position) noexcept;

    bool operator==(const Cell& other) const noexcept;

    auto die() noexcept -> void;
    auto birth(const Position& position) noexcept -> void;
    auto isAlive() const noexcept -> bool;
    auto getPosition() const noexcept -> Position;

private:
    bool m_isAlive;
    Position m_position;
};

} // namespace conlife
