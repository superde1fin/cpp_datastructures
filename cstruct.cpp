#include <boost/python.hpp>
#include "datastructures.hpp"

using namespace boost::python;


BOOST_PYTHON_MODULE(cstruct){
    class_<SQNode>("SQNode", no_init);
    class_<Stack>("Stack", init<>())
    .def("isEmpty", &Stack::isEmpty)
    .def("length", &Stack::length)
    .def("push", &Stack::push)
    .def("pop", &Stack::pop)
    .def("peek", &Stack::peek)
    .def("__str__", &Stack::toString)
    ;
    class_<Queue>("Queue", init<>())
    .def("isEmpty", &Queue::isEmpty)
    .def("length", &Queue::length)
    .def("enQ", &Queue::enQ)
    .def("deQ", &Queue::deQ)
    .def("peek_front", &Queue::peek_front)
    .def("peek_rear", &Queue::peek_rear)
    .def("__str__", &Queue::toString)
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
    .def("preorder", &BinarySearchTree::preorder)
    .def("postorder", &BinarySearchTree::postorder)
    ;
    
    class_<BTNode>("BTNode", no_init)
    .def("get_left", &BTNode::get_left)
    .def("get_right", &BTNode::get_right)
    .def("get_value", &BTNode::get_value)
    ;
    
    class_<HNode>("HNode", no_init)
    .def("get_left", &HNode::get_left)
    .def("get_right", &HNode::get_right)
    .def("get_value", &HNode::get_value)
    .def("get_parent", &HNode::get_parent)
    .def("get_height", &HNode::get_height)
    ;
    
    
    class_<AVL_Tree>("AVL_Tree", init<>())
    .def("isEmpty", &AVL_Tree::isEmpty)
    .def("insert", &AVL_Tree::insert)
    .def("erase", &AVL_Tree::erase)
    //.def("validate", &AVL_Tree::validate)
    .def("get_root", &AVL_Tree::get_root)

    ;
    }
    

