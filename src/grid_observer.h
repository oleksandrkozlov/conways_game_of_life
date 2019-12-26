#pragma once

namespace conlife {

class Grid;

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

    virtual void onGridChanged(const Grid& grid) = 0;
};

} // namespace conlife
