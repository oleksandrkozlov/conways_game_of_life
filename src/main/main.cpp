#include "destiny.h"
#include "grid.h"
#include "grid_presenter.h"
#include "position.h"

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv) noexcept
{

    // glider
    //auto grid = conlife::Grid({ 100U, 40U });
    //grid.populate({ 1U, 0U });
    //grid.populate({ 2U, 1U });
    //grid.populate({ 0U, 2U });
    //grid.populate({ 1U, 2U });
    //grid.populate({ 2U, 2U });

    // diehard
    auto grid = conlife::Grid { { 23U, 23U } };
    grid.populate({ 8U, 5U });
    grid.populate({ 9U, 5U });
    grid.populate({ 9U, 6U });
    grid.populate({ 14U, 4U });
    grid.populate({ 13U, 6U });
    grid.populate({ 14U, 6U });
    grid.populate({ 15U, 6U });

    auto gridPresenter = conlife::GridPresenter {};
    auto destiny = conlife::Destiny { std::move(grid), &gridPresenter };

    while (destiny.tick())
        ;

    return 0;
}
