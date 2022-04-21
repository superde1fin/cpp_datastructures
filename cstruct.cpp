#include <boost/python.hpp>
#include "datastructures.hpp"

using namespace boost::python;

//Non-member function overloads
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
    
    class_<LinkedList>("LinkedList")
    .def(init<>())
    //Overloaded constructor goes here
    //.def(init<int*>())
    .def("isEmpty", &LinkedList::isEmpty)
    .def("length", &LinkedList::length)
    .def("insert_head", &LinkedList::insert_head)
    .def("insert_tail", &LinkedList::insert_tail)
    .def("peek", &LinkedList::peek)
    .def("peek_tail", &LinkedList::peek_tail)
    .def("contains", &LinkedList::contains)
    .def("search", &LinkedList::search)
    //Member function overloads
    .def("remove", static_cast<int(LinkedList::*)(int)>(&LinkedList::remove))
    .def("remove", static_cast<int(LinkedList::*)(SQNode&)>(&LinkedList::remove))
    .def("insert_before", static_cast<SQNode(LinkedList::*)(int, int)>(&LinkedList::insert_before))
    .def("insert_before", static_cast<SQNode(LinkedList::*)(SQNode&, int)>(&LinkedList::insert_before))
    .def("insert_after", static_cast<SQNode(LinkedList::*)(int, int)>(&LinkedList::insert_after))
    .def("insert_after", static_cast<SQNode(LinkedList::*)(SQNode&, int)>(&LinkedList::insert_after))
    .def("insert_at", &LinkedList::insert_at)
    .def("invert", &LinkedList::invert)
    .def("remove_after", &LinkedList::remove_after)
    .def("remove_last", &LinkedList::remove_last)
    ;
    
    class_<BinarySearchTree>("BinarySearchTree", init<>())
    .def("isEmpty", &BinarySearchTree::isEmpty)
    .def("insert", &BinarySearchTree::insert)
    .def("erase", &BinarySearchTree::erase)
    .def("validate", &BinarySearchTree::validate)
    .def("get_root", &BinarySearchTree::get_root)
    .def("inorder", &BinarySearchTree::inorder)
    ;
    
    class_<BTNode>("BTNode", init<int>())
    .def("get_left", &BTNode::get_left)
    .def("get_right", &BTNode::get_right)
    .def("get_value", &BTNode::get_value)
    ;
    }
    

