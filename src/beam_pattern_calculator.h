#ifndef SRC_BEAM_PATTERN_CALCULATOR_H_
#define SRC_BEAM_PATTERN_CALCULATOR_H_

#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <iostream>

namespace py = pybind11;

class BeamPatternCalculator {
    double start_azimuth, end_azimuth, start_elevation, end_elevation;
    int n_azimuths, n_elevations;
    double main_lobe, side_lobe;
    double petal_width_azimuth, petal_width_elevation;

    Eigen::MatrixXd calculateDiagram(double, double);

 public:
    explicit BeamPatternCalculator(double, double, double, double, int, int, double, double, double, double);

    Eigen::MatrixXd calculate(const py::EigenDRef<const Eigen::MatrixXd>);
};

#endif  // SRC_BEAM_PATTERN_CALCULATOR_H_
