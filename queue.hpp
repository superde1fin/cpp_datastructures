#include "datastructures.h"
#include "SQNode.hpp"

Queue::Queue(){
    Queue::front = nullptr;
    Queue::rear = nullptr;
    Queue::size = 0;
    }

Queue::~Queue(){
    Queue::front = nullptr;
    Queue::rear = nullptr;
    Queue::size = NULL;
    }
    
bool Queue::isEmpty(){return Queue::size == 0;}
int Queue::length(){return Queue::size}
SQNode* Queue::deQ(){
    if Queue::isEmpty(){}
    }
