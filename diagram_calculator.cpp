#include "diagram_calculator.h"

DiagramCalculator::DiagramCalculator(int n) : big_mat(Eigen::MatrixXd::Zero(n, n)) {}

Eigen::MatrixXd& DiagramCalculator::getMatrix() { return this->big_mat; }

const Eigen::MatrixXd&  DiagramCalculator::viewMatrix() { return this->big_mat; }

Eigen::MatrixXd DiagramCalculator::modifyMatrix(const Eigen::Ref<const Eigen::MatrixXd> a) {
    Eigen::MatrixXd b = a;
    b(0, 0) = 1;
    return b;
}
