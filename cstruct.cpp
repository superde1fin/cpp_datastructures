#include <boost/python.hpp>
#include "datastructures.hpp"
//#include "stack.hpp"
using namespace boost::python;

string stack_toString(const Stack& stk){return toString(stk);}
string queue_toString(const Queue& que){return toString(que);}

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
    class_<Queue>("Queue", init<>())
    .def("isEmpty", &Queue::isEmpty)
    .def("length", &Queue::length)
    .def("enQ", &Queue::enQ)
    .def("deQ", &Queue::deQ)
    .def("peek_front", &Queue::peek_front)
    .def("peek_rear", &Queue::peek_rear)
    .def("__str__", &queue_toString)
    ;
    }
