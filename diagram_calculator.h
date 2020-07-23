#ifndef DIAGRAMCALCULATOR_H
#define DIAGRAMCALCULATOR_H

#include <Eigen/Dense>
#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

namespace py = pybind11;

class DiagramCalculator {
    Eigen::MatrixXd big_mat;
public:
    explicit DiagramCalculator(int);
    Eigen::MatrixXd& getMatrix();
    const Eigen::MatrixXd& viewMatrix();
    Eigen::MatrixXd modifyMatrix(const Eigen::Ref<const Eigen::MatrixXd>);
};

#endif
