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
    while(!Queue::isEmpty()){
        Queue::deQ();
        }
    Queue::size = NULL;
    }
    
bool Queue::isEmpty(){return Queue::size == 0;}

int Queue::length(){return Queue::size}

int Queue::deQ(){
    if (Queue::isEmpty()){throw empty_exc;}
    else{
        SQNode* removed = Queue::front;
        int return_value = removed -> value;
        Queue::front = front -> next;
        if(Queue::rear == removed){Queue::rear = nullptr;}
        delete removed;
        return return_value;
        }
    Queue::size--;
    }
    
SQNode Queue::enQ(int input_value){
    Queue::front = new SQNode(input_value, Queue::front);
    if(Queue::rear == nullptr){Queue::rear = Queue::front;}
    Queue::size++;
    return *Queue::front;
    }
