#include <iostream>
#include <string>

template <class node_value_type>
class SQNode{
    public:
        SQNode* next;
    private:
        node_value_type value;
        SQNode(node_value_type, SQNode*);
        SQNode(node_value_type);
        ~SQNode();
    friend class Stack;
    friend class Queue;
    friend ostream& operator << (ostream& os, SQNode& nd);
    friend string toString(SQNode& nd);
    };
    
class Queue{
    protected:
        SQNode* front;
        SQNode* rear;
        int size;
    public:
        bool isEmpty();
        int length();
        Queue();
        ~Queue();
        node_value_type deQ();
        SQNode* enQ(node_value_type);
    friend ostream& operator << (ostream& os, Queue& q);
    friend string toString(Queue& q);
    };

class Stack{
    protected:
        SQNode *head;
        int size;
        
    public:
        Stack();
        ~Stack();
        bool isEmpty();
        int length();
        SQNode* push(node_value_type);
        node_value_type pop();
        node_value_type peek(){;
        
    friend ostream& operator << (ostream& os, Stack& stk);
    friend string toString(Stack& stk);

    };
    
