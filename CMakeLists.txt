cmake_minimum_required(VERSION 3.5)

project (pybind-example)

find_package(pybind11)
find_package(Eigen3)

# adds a library pybindings that can be called by python
pybind11_add_module(beam_pattern_calculator_bind src/main.cpp)
target_link_libraries(beam_pattern_calculator_bind PRIVATE Eigen3::Eigen)

message("${pybind11_VERSION}")
message("${PYTHON_VERSION_MAJOR}.${PYTHON_VERSION_MINOR}")
message("Building with Eigen v${EIGEN3_VERSION_STRING}")
