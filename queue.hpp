#include "datastructures.h"
#include "SQNode.hpp"

class EmptyStackException: public runtime_error{
    public: EmptyStackException(): runtime_error("Empty Queue"){}
    }empty_exc;
    

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

node_value_type Queue::deQ(){
    if (Queue::isEmpty()){throw empty_exc;}
    else{
        SQNode* removed = Queue::front;
        node_type_value return_value = *removed;
        Queue::front = front -> next;
        if(Queue::rear == removed){Queue::rear = nullptr;}
        delete removed;
        return return_value;
        }
    }
    
SQNode Queue::enQ(node_value_type input_value){
    Queue::front = new SQNode(input_value, Queue::front);
    if(Queue::rear == nullptr){Queue::rear = Queue::front;}
    return Queue::front;
    }
