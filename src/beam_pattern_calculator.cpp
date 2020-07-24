#include "beam_pattern_calculator.h"

BeamPatternCalculator::BeamPatternCalculator(double start_azimuth, double end_azimuth,
    double start_elevation, double end_elevation,
    int n_azimuths, int n_elevations,
    double main_lobe, double side_lobe,
    double lobe_width_azimuth, double lobe_width_elevation) :
    start_azimuth_(start_azimuth), start_elevation_(start_elevation),
    n_azimuths_(n_azimuths), n_elevations_(n_elevations),
    main_lobe_(main_lobe), side_lobe_(side_lobe),
    lobe_width_azimuth_(lobe_width_azimuth), lobe_width_elevation_(lobe_width_elevation),
    azimuth_angle_step_((end_azimuth - start_azimuth) / (n_azimuths - 1)),
    elevation_angle_step_((end_elevation - start_elevation) / (n_elevations - 1)),
    cos1_coeff_(M_PI_2 / lobe_width_azimuth), cos2_coeff_(M_PI_2 / lobe_width_elevation) {
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
        if (!(-90. < lobe_width_azimuth && lobe_width_azimuth < 90.)) {
            throw std::invalid_argument("Lobe width azimuth must be in [-90, 90]");
        }
        if (!(-90. < lobe_width_elevation && lobe_width_elevation < 90.)) {
            throw std::invalid_argument("Lobe width elevation must be in [-90, 90]");
        }
    }

std::vector<Eigen::MatrixXd> BeamPatternCalculator::calculate(
    const py::EigenDRef<const Eigen::MatrixXd> installation_angles) {
    if (installation_angles.cols() != 2) {
        throw std::invalid_argument("Installation angles matrix shape should be (n, 2)");
    }
    std::vector<Eigen::MatrixXd> grid_vector;
    for (int i = 0; i < installation_angles.rows(); ++i) {
        grid_vector.push_back(calculateDiagram(installation_angles(i, 0), installation_angles(i, 1)));
    }
    return grid_vector;
}

Eigen::MatrixXd BeamPatternCalculator::calculateDiagram(double installation_azimuth, double installation_elevation) {
    if (!(-90. < installation_azimuth && installation_azimuth < 90.)) {
        throw std::invalid_argument("Installation azimuth must be in [-90, 90]");
    }
    if (!(-90. < installation_elevation && installation_elevation < 90.)) {
        throw std::invalid_argument("Installation elevation must be in [-90, 90]");
    }
    double installation_azimuth_cos = std::cos(installation_azimuth);
    double installation_elevation_cos = std::cos(installation_elevation);
    double diff_max1 = this->lobe_width_azimuth_ / installation_azimuth_cos;
    double diff_max2 = this->lobe_width_elevation_ / installation_elevation_cos;

    Eigen::MatrixXd grid(this->n_azimuths_, this->n_elevations_);
    double azimuth_angle = this->start_azimuth_, elevation_angle;

    for (int azimuth_step = 0; azimuth_step < this->n_azimuths_; ++azimuth_step) {
        elevation_angle = this->start_elevation_;
        for (int elevation_step = 0; elevation_step < this->n_elevations_; ++elevation_step) {
            double angle_diff1 = azimuth_angle - installation_azimuth;
            double angle_diff2 = elevation_angle - installation_elevation;
            double cos1 = std::cos(this->cos1_coeff_ * angle_diff1 * installation_azimuth_cos);
            double cos2 = std::cos(this->cos2_coeff_ * angle_diff2 * installation_elevation_cos);
            double lobe_coeff = (std::abs(angle_diff1) < diff_max1 && std::abs(angle_diff2) < diff_max2) ?
            this->main_lobe_ : this->side_lobe_;
            grid(azimuth_step, elevation_step) = std::abs(cos1 * cos2) * lobe_coeff;
            elevation_angle += this->elevation_angle_step_;
        }
        azimuth_angle += this->azimuth_angle_step_;
    }
    return grid;
}
