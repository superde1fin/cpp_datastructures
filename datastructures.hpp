#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include "datastructures.h"

using namespace std;

class EmptyStackException: public runtime_error{
    public: EmptyStackException(): runtime_error("Empty Stack"){}
    }empty_stack_exc;

class EmptyQueueException: public runtime_error{
    public: EmptyQueueException(): runtime_error("Empty Queue"){}
    }empty_queue_exc;
    
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

Stack::Stack(){
        Stack::head = nullptr;
        Stack::size = 0;
        }
Stack::~Stack(){
        while(!Stack::isEmpty()){pop();}
        }
        
bool Stack::isEmpty(){return Stack::size == 0;}
        
int Stack::length(){return Stack::size;}
        
SQNode Stack::push(int value){
    Stack::head = new SQNode(value,Stack::head);
    Stack::size ++;
    return *Stack::head;
    }
        
int Stack::pop(){
    if (Stack::isEmpty()){
        throw empty_stack_exc;
        }
    else{
        SQNode* removed = Stack::head;
        int value = removed -> value;
        Stack::head = Stack::head -> next;
        delete removed;
        Stack::size --;
        return value;
    }
}

int Stack::peek(){
    if(Stack::isEmpty()){
            throw empty_stack_exc;
            }
        return Stack::head -> value;
    }
    
    

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

int Queue::length(){return Queue::size;}

int Queue::deQ(){
    if (Queue::isEmpty()){throw empty_queue_exc;}
    else{
        SQNode* removed = Queue::front;
        int return_value = removed -> value;
        Queue::front = front -> next;
        if(removed == Queue::rear){Queue::rear = nullptr;}
        delete removed;
        Queue::size--;
        return return_value;
        }
    }
    
SQNode Queue::enQ(int input_value){
    SQNode* new_node = new SQNode(input_value);
    if(Queue::isEmpty()){
        Queue::rear = new_node;
        Queue::front = new_node;
        }else{
            Queue::rear -> next = new_node;
            Queue::rear = new_node;
            }
    Queue::size++;
    return *Queue::rear;
    }
    
int Queue::peek_front(){if(!Queue::isEmpty()){return Queue::front -> value;}else throw empty_queue_exc;}
int Queue::peek_rear(){if(!Queue::isEmpty()){return Queue::rear -> value;}else throw empty_queue_exc;}


inline string toString(const SQNode& node){
    stringstream ss;
    ss << node.value;
    return ss.str();
    }
    
inline string toString(const Stack& stk) {
        string result = "Top -> ";
        SQNode* node = stk.head;
        while(node){
            result = result + "[" + toString((*node)) + "]";
            node = node -> next;
        }
        result += " <- Bottom";
        return result;
    }
    
inline string toString(const Queue& que) {
        string result = "Front -> ";
        SQNode* node = que.front;
        while(node){
            result = result + "[" + toString((*node)) + "]";
            node = node -> next;
        }
        result += " <- Rear";
        return result;
    }

