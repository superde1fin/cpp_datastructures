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

class LinkedList{
    protected:
        SQNode* head;
        SQNode* tail;
    public:
        LinkedList();
        LinkedList(int*);
        ~LinkedList();
        bool isEmpty();
        int length();
        int peek();
        int peek_front();
        SQNode insert_head(int);
        SQNode insert_tail(int);
        SQNode search(int);
        SQNode remove(int);
        SQNode remove(SQNode&);
        SQNode insert_after(SQNode&, int);
        //insert after a value
        SQNode insert_after(int, int);
        //insert before a balue
        SQNode insert_before(int, int);
        //insert at an index
        SQNode insert_at(int, int);
        LinkedList inverted();
        //Remove after value
        SQNode remove_after(int);
        //Remove last by value
        SQNode remove_last(int);
        LinkedList flatten();
    };
    
