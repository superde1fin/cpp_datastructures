#include <boost/python.hpp>
#include "datastructures.hpp"
//#include "stack.hpp"
using namespace boost::python;

string stack_toString(const Stack& stk){return toString(stk);}

BOOST_PYTHON_MODULE(cstruct){
    class_<SQNode>("SQNode", no_init);
    class_<Stack>("Stack", init<>())
    .def("isEmpty", &Stack::isEmpty)
    .def("length", &Stack::length)
    .def("push", &Stack::push)
    .def("pop", &Stack::pop)
    .def("peek", &Stack::peek)
    .def("__str__", &stack_toString)
    ;
    }
