#include "beam_pattern_calculator.cpp"

namespace py = pybind11;

PYBIND11_MODULE(beam_pattern_calculator, m) {
  m.doc() = "beam pattern calculator module";

  py::class_<BeamPatternCalculator>(m, "BeamPatternCalculator")
    .def(py::init<double, double, double, double, int, int, double, double, double, double>())
    .def("calculate", &BeamPatternCalculator::calculate,
    py::return_value_policy::reference_internal, py::arg().noconvert());
}
