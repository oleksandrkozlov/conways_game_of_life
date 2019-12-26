add_library(core STATIC cell.cpp grid.cpp destiny.cpp grid_presenter.cpp)

target_include_directories(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
