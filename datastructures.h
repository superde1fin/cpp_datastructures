template <class node_value_type>
class SQNode{
    public:
        SQNode* next;
    private:
        SQNode(node_value_type, Node*);
        SQNode(node_value_type);
        ~SQNode();
    friend class Stack;
    friend class Queue;
    friend ostream& operator << (ostream& os, Node& nd);
    friend string toString(Node& nd);
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
        SQNode* deQ();
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
        int push(node_value_type);
        int pop();
        int peek(){;
        
    friend ostream& operator << (ostream& os, Stack& stk);
    friend string toString(Stack& stk);

    };
    
