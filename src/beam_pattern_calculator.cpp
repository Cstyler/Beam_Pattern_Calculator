#include "beam_pattern_calculator.h"

BeamPatternCalculator::BeamPatternCalculator(double start_azimuth, double end_azimuth,
    double start_elevation, double end_elevation,
    int n_azimuths, int n_elevations,
    double main_lobe, double side_lobe,
    double lobe_width_azimuth, double lobe_width_elevation) :
    start_azimuth(start_azimuth), end_azimuth(end_azimuth),
    start_elevation(start_elevation), end_elevation(end_elevation),
    n_azimuths(n_azimuths), n_elevations(n_elevations),
    main_lobe(main_lobe), side_lobe(side_lobe),
    lobe_width_azimuth(lobe_width_azimuth), lobe_width_elevation(lobe_width_elevation) {
        if (!(-90. < start_azimuth && start_azimuth < 90.)) {
            throw std::invalid_argument("Start azimuth must be in [-90, 90]");
        }
        if (!(-90. < end_azimuth && end_azimuth < 90.)) {
            throw std::invalid_argument("End azimuth must be in [-90, 90]");
        }
        if (start_azimuth > end_azimuth) {
            std::cout << "Start azimuth greater then end" << std::endl;
            throw std::invalid_argument("Start azimuth greater then end");
        }
        if (!(-90. < start_elevation && start_elevation < 90.)) {
            throw std::invalid_argument("Start elevation must be in [-90, 90]");
        }
        if (!(-90. < end_elevation && end_elevation < 90.)) {
            throw std::invalid_argument("End elevation must be in [-90, 90]");
        }
        if (start_elevation > end_elevation) {
            throw std::invalid_argument("Start elevation greater then end");
        }
    }

std::vector<Eigen::MatrixXd> BeamPatternCalculator::calculate(const py::EigenDRef<const Eigen::MatrixXd> installation_angles) {
    if (installation_angles.cols() != 2) {
        throw std::invalid_argument("Angles matrix shape should be (n, 2)");
    }
    std::vector<Eigen::MatrixXd> res;
    res.push_back(installation_angles);
    for (int i = 0; i < installation_angles.rows(); ++i) {
        Eigen::MatrixXd a = calculateDiagram(installation_angles(i, 0), installation_angles(i, 1));
    }
    return res;
}

Eigen::MatrixXd BeamPatternCalculator::calculateDiagram(double installation_azimuth, double installation_elevation) {
    Eigen::MatrixXd res(this->n_azimuths, this->n_elevations);
    double grid_width = this->end_azimuth - this->start_azimuth;
    double azimuth_step = grid_width / this->n_azimuths;
    double grid_height = this->end_elevation - this->start_elevation;
    double elevation_step = grid_height / this->n_elevations;
    return res;
}
