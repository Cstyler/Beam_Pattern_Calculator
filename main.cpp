#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>
#include "diagram_calculator.cpp"
#include <iostream>

namespace py = pybind11;

// define a module to be imported by python
PYBIND11_MODULE(diagram_calculator, m) {
  using namespace pybind11::literals;
  m.doc() = "diagram calculator module";

  py::class_<DiagramCalculator>(m, "DiagramCalculator")
    // .def(py::init<int>())
    .def(py::init<int>())
    .def("copy_matrix", &DiagramCalculator::getMatrix) // Makes a copy!
    .def("get_matrix", &DiagramCalculator::getMatrix, py::return_value_policy::reference_internal)
    .def("view_matrix", &DiagramCalculator::viewMatrix, py::return_value_policy::reference_internal)
    .def("modify_matrix", &DiagramCalculator::modifyMatrix, py::return_value_policy::reference_internal, py::arg().noconvert());
}
