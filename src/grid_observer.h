#pragma once

#include <vector>

namespace conlife {

using GridData = std::vector<std::vector<bool>>;

class GridObserver
{
protected:
    GridObserver() = default;
    GridObserver(GridObserver&&) = default;
    GridObserver(const GridObserver&) = default;

    GridObserver& operator=(GridObserver&&) = default;
    GridObserver& operator=(const GridObserver&) = default;

public:
    virtual ~GridObserver() = default;

    virtual void onGridChanged(const GridData& grid) = 0;
};

} // namespace conlife
