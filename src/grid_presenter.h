#pragma once

#include "grid_observer.h"

namespace conlife {

class GridPresenter : public GridObserver {
private:
    void onGridChanged(const GridData& grid) override;
};

} // namespace conlife
