#include <iostream>
#include <string>

using namespace std;

class SQNode{
    public:
        SQNode* next;
        SQNode(int, SQNode*);
        SQNode(int);
        ~SQNode();
    private:
        int value;

    
    friend class Stack;
    friend class Queue;
    friend ostream& operator << (ostream& os, const SQNode& nd);
    friend string toString(const SQNode& nd);
    friend void initialize_node_constructors();
    };
    
class Queue{
protected:
//public:
        SQNode* front;
        SQNode* rear;
        int size;
    public:
        bool isEmpty();
        int length();
        Queue();
        ~Queue();
        int deQ();
        SQNode enQ(int);
    friend ostream& operator << (ostream& os, const Queue& q);
    friend string toString(const Queue& q);
    };

class Stack{
    protected:
    //public:
        SQNode *head;
        int size;
        
    public:
        Stack();
        ~Stack();
        bool isEmpty();
        int length();
        SQNode push(int);
        int pop();
        int peek();
        
    friend ostream& operator << (ostream& os, const Stack& stk);
    friend string toString(const Stack& stk);
    };
    
