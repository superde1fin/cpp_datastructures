#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include "datastructures.h"
#include "SQNode.hpp"

using namespace std;

class EmptyStackException: public runtime_error{
    public: EmptyStackException(): runtime_error("Empty Stack"){}
    }empty_exc;
    

Stack::Stack(){
        SQNode* Stack::head = nullptr;
        Stack::size = 0;
        }
Stack::~Stack(){
        while(!Stack::isEmpty()){
            //cout << "Running destructor" << endl;
            pop();
            }
        }
        
bool Stack::isEmpty(){return Stack::size == 0;}
        
int Stack::length(){return Stack::size;}
        
int Stack::push(int value){
    Stack::head = new SQNode(value,Stack::head);
    Stack::size ++;
    return 0;
    }
        
int Stack::pop(){
    if (Stack::isEmpty()){
        throw empty_exc;
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
            throw empty_exc;
            }
        return Stack::head -> value;
    }
    
    
inline string toString(SQNode& node){
    stringstream ss;
    ss << node.value;
    return ss.str();
    }
    
inline string toString(Stack& stk) {
        //string result = "Top -> ";
        //Node* node = stk.head;
        //while(node){
            //result = result + "[" + toString((*node)) + "]";
            //node = node -> next;
        //}
        //result += " <- Bottom";
        //return result;
        return "Printed stack here";
    }

ostream& operator << (ostream& os,const SQNode& nd){
    ostringstream oss;
    oss << nd.value;
    return os << oss.str();
    }
    
ostream& operator << (ostream& os,const Stack& stk){
    ostringstream oss;
    oss << "Top -> ";
    SQNode* node = stk.head;
    while(node){
        oss << "[" << *node << "]";
        node = node -> next;
    }
    oss << " <- Bottom";
    return os << oss.str();
    }

