#include <pybind11/pybind11.h>
namespace py = pybind11;

struct Pet {
    Pet(const std::string &name) : name(name) { }
    std::string name;
};

struct Dog : Pet {
    Dog(const std::string &name) : Pet(name) { }
    std::string bark() const { return "woof!"; }
};

PYBIND11_MODULE(pet4, m) {
  py::class_<Pet>(m, "Pet")
    .def(py::init<const std::string &>())
    .def_readwrite("name", &Pet::name);

  // Method 1: template parameter:
  py::class_<Dog, Pet /* <- specify C++ parent type */>(m, "Dog")
  // this also works:
  // py::class_<Dog>(m, "Dog", pet /* <- specify Python parent type */)
      .def(py::init<const std::string &>())
      .def("bark", &Dog::bark);
}
