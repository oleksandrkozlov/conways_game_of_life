#include "grid_presenter.h"
#include "grid.h"

#include <chrono>
#include <iostream>
#include <string>
#include <thread>

namespace conlife {
namespace {

    auto printGrid(const GridData& grid) -> void;

} // namespace

void GridPresenter::onGridChanged(const GridData& grid)
{
    printGrid(grid);
}

namespace {

    auto printGrid(const GridData& grid) -> void
    {
        std::system("clear");

        for (const auto& column : grid) {
            for (auto cell : column) {
                if (cell) {
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
