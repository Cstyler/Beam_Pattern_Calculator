#include "diagram_calculator.cpp"

namespace py = pybind11;

// define a module to be imported by python
PYBIND11_MODULE(diagram_calculator, m) {
  m.doc() = "diagram calculator module";

  py::class_<DiagramCalculator>(m, "DiagramCalculator")
    // .def(py::init<int>())
    .def(py::init<double, double, double, double, int, int, double, double, double, double>())
    .def("calculate", &DiagramCalculator::calculate,
    py::return_value_policy::reference_internal, py::arg().noconvert());
}
