#include <pybind11/pybind11.h>
namespace py = pybind11;

struct Pet {
    Pet() {}
    std::string name;
};

PYBIND11_MODULE(pet3, m) {
    py::class_<Pet>(m, "Pet", py::dynamic_attr())
        .def(py::init<>())
        .def_readwrite("name", &Pet::name);
}
