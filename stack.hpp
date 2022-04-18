#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class EmptyStackException: public runtime_error{
    public: EmptyStackException(): runtime_error("Empty Stack"){}
    }empty_exc;

class Node{
    public:
        Node *next;
    private:
    int value;
    
    Node(int input_value){
        value = input_value;
        next = nullptr;
        }
                
    Node(int input_value, Node *input_next){
        value = input_value;
        next = input_next;
        }
        
    ~Node(){
        next = nullptr;
        }
    friend class Stack;
    friend ostream& operator << (ostream& os, Node& nd);
    };

class Stack{
    protected:
        Node *head;
        int size;
        
    public:
        Stack(){
            Node *head = nullptr;
            size = 0;
            }
    ~Stack(){
            while(!isEmpty()){
                //cout << "Running destructor" << endl;
                pop();
                }
            }
            
        bool isEmpty(){
            return size == 0;
            }
            
        int length(){
            return size;
            }
            
        int push(int value){
            head = new Node(value,head);
            size ++;
            return 0;
            }
            
        int pop(){
            if (isEmpty()){
                throw empty_exc;
                }
            else{
                Node* removed = head;
                int value = removed -> value;
                head = head -> next;
                delete removed;
                size --;
                return value;
            }
        }
    
    int peek();
        
    friend ostream& operator << (ostream& os, Stack& stk);
    };

int Stack :: peek(){
            if(isEmpty()){
                throw empty_exc;
                }
            return head -> value;
            }

ostream& operator << (ostream& os, Node& nd){
    os << nd.value;
    return os;
    }
    
ostream& operator << (ostream& os, Stack& stk){
    os << "Top -> ";
    Node* node = stk.head;
    while(node){
        os << "[" << *node << "]";
        node = node -> next;
    }
    os << " <- Bottom";
    return os;
    }

