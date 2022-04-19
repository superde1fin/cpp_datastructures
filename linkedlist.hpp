#include "datastructures.h"
#include "SQNode.hpp"

using namespace std;

class EmptyStackException: public runtime_error{
    public: EmptyStackException(): runtime_error("Empty Linked List"){}
    }empty_exc;

LinkedList::LinkedList(){
    LinkedList::head = nullptr;
    LinkedList::tail = nullptr;
    LinkedList::size = 0;
    }
    
LinkedList::LinkedList(int* array){
    int arr_len = *(&array + 1) - array;
    LinkedList::size = 0;
    for(int i = 0; i < arr_len; i++){
        LinkedList::insert_head(a[i]);
        }
    }

bool LinkedList::isEmpty(){return LinkedList::size == 0;}

int LinkedList::length(){return LinkedList::size;}

SQNode LinkedList::insert_head(int value){
    SQNode* new_node = new SQNode(value, LinkedList::head)
    if(LinkedList::tail == nullptr){LinkedList::rear = new_node;}
    LinkedList::size++;
    return *new_node;
    }
    
SQNode LinkedList::insert_tail(int value){
    SQNode* new_node = new SQNode(value);
    if(LinkedList::front == nullptr){LinkedList::front = new_node;}
    LinkedList::size++;
    return *new_node;
    }

LinkedList::~LinkedList(){
    while(!LinkedList::isEmpty()){
        LinkedList::remove_head();
        }
    LinkedList::size = NULL;
    }

//O(1)
int LinkedList::remove_head(){
    if (LinkedList::isEmpty()){throw empty_exc;}
    else{
        SQNode* removed = LinkedList::head;
        int return_value = removed -> value;
        LinkedList::front = head -> next;
        if(LinkedList::tail == removed){LinkedList::tail = nullptr;}
        delete removed;
        }
    LinkedList::size--;
    return return_value;
    }

//O(n)
int LinkedList::remove_tail(){
    if (LinkedList::isEmpty()){throw empty_exc;}
    else{
        SQNode* node = LinkedList::head;
        while(node -> next != LinkedList::tail){node = node -> next;}
        LinkedList::tail = node;
        int return_value = node -> next -> value;
        delete node -> next;
        }
    LinkedList::size--;
    return return_value;
    }
    
int LinkedList::peek(){return LinkedList::head -> value;}

int LinkedList::peek_tail(return LinkedList::tail -> value;)

SQNode LinkedList::search(int value){
    SQNode* node = LinkedList::head;
    while(node != nullptr || node -> value != value){node = node -> next;}
    if(node == nullptr){return NULL;}else{return *node;}
    }
    
int LinkedList::remove(int value){
    SQNode* node = LinkedList::head;
    if(node -> value == value){return LinkedList::remove_head();}
    while(node -> next != nullptr || node -> next -> value != value){node = node -> next;}
    if(node -> next == nullptr){return NULL;}
    SQNode* to_del = node -> next;
    int return_value = to_del -> value;
    node -> next = node -> next -> next;
    delete to_del;
    return return_value;
    }
    
int LinkedList::remove(SQNode* to_remove){
    SQNode* node = LinkedList::head;
    if(node == to_remove){return LinkedList::remove_head();}
    while(node -> next != nullptr || node -> next != to_remove){node = node -> next;}
    if(node -> next == nullptr){return NULL;}
    SQNode* to_del = node -> next;
    SQNode return_node = *to_del;
    node -> next = node -> next -> next;
    delete to_del;
    return return_node;
    }
    



