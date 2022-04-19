#include "datastructures.h"

SQNode::SQNode(int input_value, SQNode* next){
    SQNode::value = input_value;
    SQNode::next = next;
    }
SQNode::SQNode(int input_value){
    SQNode::value = input_value;
    SQNode::next = nullptr;
    }
SQNode::~SQNode(){
    SQNode::value = NULL;
    SQNode::next = nullptr;
    }
