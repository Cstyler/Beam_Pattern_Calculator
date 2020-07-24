#include "diagram_calculator.h"

DiagramCalculator::DiagramCalculator(double start_azimuth, double end_azimuth,
    double start_elevation, double end_elevation,
    int n_azimuths, int n_elevations,
    double main_petal, double side_petal,
    double petal_width_azimuth, double petal_width_elevation) :
    start_azimuth(start_azimuth), end_azimuth(end_azimuth),
    start_elevation(start_elevation), end_elevation(end_elevation),
    n_azimuths(n_azimuths), n_elevations(n_elevations),
    main_petal(main_petal), side_petal(side_petal),
    petal_width_azimuth(petal_width_azimuth), petal_width_elevation(petal_width_elevation) {
        std::cout << start_azimuth << std::endl;
        if (!(-90. < start_azimuth < 90.)) {
            throw std::invalid_argument("Start azimuth must be in [-90, 90]");
        }
        if (!(-90. < end_azimuth < 90.)) {
            std::cout << "End azimuth must be in [-90, 90]" << std::endl;
        }
        if (start_azimuth > end_azimuth) {
            std::cout << "Start azimuth greater then end" << std::endl;
        }
        if (!(-90. < start_elevation < 90.)) {
            std::cout << "Start elevation must be in [-90, 90]" << std::endl;
        }
        if (!(-90. < end_elevation < 90.)) {
            std::cout << "End elevation must be in [-90, 90]" << std::endl;
        }
        if (start_elevation > end_elevation) {
            std::cout << "Start elevation greater then end" << std::endl;
        }
    }

Eigen::MatrixXd DiagramCalculator::calculate(const py::EigenDRef<const Eigen::MatrixXd> installation_angles) {
    if (installation_angles.cols() != 2) {
        std::cout << "Angles matrix shape should be (n, 2)" << std::endl;
    }
    for (int i = 0; i < installation_angles.rows(); ++i) {
        Eigen::MatrixXd a = calculateDiagram(installation_angles(i, 0), installation_angles(i, 1));
    }
    return installation_angles;
}

Eigen::MatrixXd DiagramCalculator::calculateDiagram(double installation_azimuth, double installation_elevation) {
    Eigen::MatrixXd res(this->n_azimuths, this->n_elevations);
    double grid_width = this->end_azimuth - this->start_azimuth;
    double azimuth_step = grid_width / this->n_azimuths;
    double grid_height = this->end_elevation - this->start_elevation;
    double elevation_step = grid_height / this->n_elevations;
    return res;
}
