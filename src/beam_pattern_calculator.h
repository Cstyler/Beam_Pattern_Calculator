#ifndef SRC_BEAM_PATTERN_CALCULATOR_H_
#define SRC_BEAM_PATTERN_CALCULATOR_H_

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/eigen.h>
#include <cmath>
#include <iostream>

namespace py = pybind11;

class BeamPatternCalculator {
    double start_azimuth_, start_elevation_;
    int n_azimuths_, n_elevations_;
    double main_lobe_, side_lobe_;
    double lobe_width_azimuth_, lobe_width_elevation_;
    double azimuth_angle_step_, elevation_angle_step_, cos1_coeff_, cos2_coeff_;

    Eigen::MatrixXd calculateDiagram(double, double);
 public:
    explicit BeamPatternCalculator(double, double, double, double, int, int, double, double, double, double);

    std::vector<Eigen::MatrixXd> calculate(const py::EigenDRef<const Eigen::MatrixXd>);
};

#endif  // SRC_BEAM_PATTERN_CALCULATOR_H_
