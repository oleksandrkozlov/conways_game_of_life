#pragma once

#include <cstddef>

namespace conlife {

struct Coordinates
{
    bool operator==(const Coordinates& other) const noexcept
    {
        return (x == other.x) && (y == other.y);
    }

    std::size_t x = 0U;
    std::size_t y = 0U;
};

} // namespace conlife
