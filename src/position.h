#pragma once

#include <cstddef>

namespace conlife {

struct Position {
    auto operator==(const Position& other) const noexcept -> bool
    {
        return (x == other.x) && (y == other.y);
    }

    std::size_t x = 0U;
    std::size_t y = 0U;
};

} // namespace conlife
