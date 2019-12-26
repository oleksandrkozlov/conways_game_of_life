#include "grid_presenter.h"
#include "grid.h"

#include <chrono>
#include <iostream>
#include <string>
#include <thread>

namespace conlife {
namespace {

    auto printGrid(const Grid& grid) -> void;

} // namespace

void GridPresenter::onGridChanged(const Grid& grid)
{
    printGrid(grid);
}

namespace {

    auto printGrid(const Grid& grid) -> void
    {
        std::system("clear");

        const auto size = grid.getSize();

        for (auto y = 0U; y < size.height; ++y) {
            for (auto x = 0U; x < size.width; ++x) {
                auto cell = grid.getCell({ x, y });
                if (cell.isAlive()) {
                    using namespace std::string_literals;
                    const auto reset = "\033[0m"s;
                    const auto red = "\033[1m\033[41m"s;
                    const auto square = "  ";
                    std::cout << red << square << reset;
                } else {
                    std::cout << ". ";
                }
            }
            std::cout << '\n';
        }

        using namespace std::chrono_literals;
        std::this_thread::sleep_for(80ms);
    }

} // namespace
} // namespace conlife
