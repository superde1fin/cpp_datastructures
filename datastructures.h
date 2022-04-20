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
        int peek_front();
        int peek_rear();
        
    friend string toString(const Queue& que);
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
        int peek_tail();
        SQNode insert_head(int);
        int remove_head();
        int remove_tail();
        SQNode insert_tail(int);
        //Search by value
        SQNode search(int);
        //Remove by value
        int remove(int);
        int remove(SQNode&);
        SQNode insert_after(SQNode&, int);
        //insert after value
        SQNode insert_after(int, int);
        //insert before a value
        SQNode insert_before(int, int);
        SQNode insert_before(SQNode&, int);
        //insert at an index
        SQNode insert_at(int, int);
        void invert();
        int remove_after(SQNode&);
        //Remove last by value
        int remove_last(int);
        void flatten();
    };
    
