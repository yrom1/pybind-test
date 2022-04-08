// cppimport
#include <pybind11/pybind11.h>

namespace py = pybind11;

#include <iostream>

void hello() {
    std::cout << "hi, compiled code!\n";
}

PYBIND11_MODULE(somecode, m) {
    m.def("hello", &hello);
}
/*
<%
setup_pybind11(cfg)
%>
*/
