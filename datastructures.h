template <class node_value_type>
class QNode{
    public:
        Node* next;
    private:
        Node(node_value_type, Node*);
        Node(node_value_type);
        ~Node();
    friend class Stack;
    friend class Queue;
    friend ostream& operator << (ostream& os, Node& nd);
    friend string toString(Node& nd);
    };
    
class Queue{
    protected:
        Node* front;
        Node* rear;
        int size;
    public:
        bool isEmpty();
        int length();
        Queue();
        ~Queue();
        Node* deQ();
        Node* enQ(node_value_type);
    friend ostream& operator << (ostream& os, Queue& q);
    friend string toString(Queue& q);
    };

class Stack{
    protected:
        Node *head;
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
    
