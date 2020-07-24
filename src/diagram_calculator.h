#ifndef DIAGRAM_CALCULATOR_H_
#define DIAGRAM_CALCULATOR_H_

#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <iostream>

namespace py = pybind11;

class DiagramCalculator {
    double start_azimuth, end_azimuth, start_elevation, end_elevation;
    int n_azimuths, n_elevations;
    double main_petal, side_petal;
    double petal_width_azimuth, petal_width_elevation;

    Eigen::MatrixXd calculateDiagram(double, double);

 public:
    explicit DiagramCalculator(double, double, double, double, int, int, double, double, double, double);

    Eigen::MatrixXd calculate(const py::EigenDRef<const Eigen::MatrixXd>);
};

#endif  // DIAGRAM_CALCULATOR_H_
