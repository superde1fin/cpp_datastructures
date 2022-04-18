#include <boost/python.hpp>
#include "stack.hpp"

using namespace boost::python;

BOOST_PYTHON_MODULE(cstruct){
    class_<Stack>("Stack", no_init)
    .def("isEmpty", &Stack::isEmpty)
    .def("length", &Stack::length)
    .def("push", &Stack::push)
    .def("pop", &Stack::pop)
    .def("peek", &Stack::peek);
    }
