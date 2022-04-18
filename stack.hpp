#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>

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
    friend ostream& operator << (ostream& os, const Node& nd);
    friend string toString(Node& stk);
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
    
    int peek(){
        if(isEmpty()){
                throw empty_exc;
                }
            return head -> value;
        }
        
    friend ostream& operator << (ostream& os, const Stack& stk);
    friend string toString(Stack& stk);

    };
    
inline string toString(Node& node){
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

inline string test(int a){
    return "test";
    }
    
inline string test(bool a){
    return "test";
    }

ostream& operator << (ostream& os,const Node& nd){
    ostringstream oss;
    oss << nd.value;
    return os << oss.str();
    }
    
ostream& operator << (ostream& os,const Stack& stk){
    ostringstream oss;
    oss << "Top -> ";
    Node* node = stk.head;
    while(node){
        oss << "[" << *node << "]";
        node = node -> next;
    }
    oss << " <- Bottom";
    return os << oss.str();
    }

