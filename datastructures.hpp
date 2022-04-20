#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include "datastructures.h"

using namespace std;
//Exceptions
//==================================================================================
class EmptyStackException: public runtime_error{
    public: EmptyStackException(): runtime_error("Empty Stack"){}
    }empty_stack_exc;

class EmptyQueueException: public runtime_error{
    public: EmptyQueueException(): runtime_error("Empty Queue"){}
    }empty_queue_exc;
    
class EmptyLinkedListException: public runtime_error{
    public: EmptyLinkedListException(): runtime_error("Empty Linked List"){}
    }empty_linkedlist_exc;
    
//SQNode
//==================================================================================
SQNode::SQNode(int input_value, SQNode* next){
    SQNode::value = input_value;
    SQNode::next = next;
    }
SQNode::SQNode(int input_value){
    SQNode::value = input_value;
    SQNode::next = nullptr;
    }
SQNode::~SQNode(){
    SQNode::value = NULL;
    SQNode::next = nullptr;
    }

//Stack
//==================================================================================
Stack::Stack(){
        Stack::head = nullptr;
        Stack::size = 0;
        }
Stack::~Stack(){
        while(!Stack::isEmpty()){pop();}
        }
        
bool Stack::isEmpty(){return Stack::size == 0;}
        
int Stack::length(){return Stack::size;}
        
SQNode Stack::push(int value){
    Stack::head = new SQNode(value,Stack::head);
    Stack::size ++;
    return *Stack::head;
    }
        
int Stack::pop(){
    if (Stack::isEmpty()){
        throw empty_stack_exc;
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
            throw empty_stack_exc;
            }
        return Stack::head -> value;
    }
    
    
//Queue
//==================================================================================
Queue::Queue(){
    Queue::front = nullptr;
    Queue::rear = nullptr;
    Queue::size = 0;
    }

Queue::~Queue(){
    Queue::front = nullptr;
    Queue::rear = nullptr;
    Queue::size = NULL;
    }
    
bool Queue::isEmpty(){return Queue::size == 0;}

int Queue::length(){return Queue::size;}

int Queue::deQ(){
    if (Queue::isEmpty()){throw empty_queue_exc;}
    else{
        SQNode* removed = Queue::front;
        int return_value = removed -> value;
        Queue::front = front -> next;
        if(removed == Queue::rear){Queue::rear = nullptr;}
        delete removed;
        Queue::size--;
        return return_value;
        }
    }
    
SQNode Queue::enQ(int input_value){
    SQNode* new_node = new SQNode(input_value);
    if(Queue::isEmpty()){
        Queue::rear = new_node;
        Queue::front = new_node;
        }else{
            Queue::rear -> next = new_node;
            Queue::rear = new_node;
            }
    Queue::size++;
    return *Queue::rear;
    }
    
int Queue::peek_front(){if(!Queue::isEmpty()){return Queue::front -> value;}else throw empty_queue_exc;}
int Queue::peek_rear(){if(!Queue::isEmpty()){return Queue::rear -> value;}else throw empty_queue_exc;}


inline string toString(const SQNode& node){
    stringstream ss;
    ss << node.value;
    return ss.str();
    }
    
inline string toString(const Stack& stk) {
        string result = "Top -> ";
        SQNode* node = stk.head;
        while(node){
            result = result + "[" + toString((*node)) + "]";
            node = node -> next;
        }
        result += " <- Bottom";
        return result;
    }
    
inline string toString(const Queue& que) {
        string result = "Front -> ";
        SQNode* node = que.front;
        while(node){
            result = result + "[" + toString((*node)) + "]";
            node = node -> next;
        }
        result += " <- Rear";
        return result;
    }

//Linked List
//==================================================================================
LinkedList::LinkedList(){
    LinkedList::head = nullptr;
    LinkedList::tail = nullptr;
    LinkedList::size = 0;
    }
    
LinkedList::LinkedList(int* array){
    int arr_len = *(&array + 1) - array;
    LinkedList::size = 0;
    for(int i = 0; i < arr_len; i++){
        LinkedList::insert_head(array[i]);
        }
    }

bool LinkedList::isEmpty(){return LinkedList::size == 0;}

int LinkedList::length(){return LinkedList::size;}

SQNode LinkedList::insert_head(int value){
    SQNode* new_node = new SQNode(value, LinkedList::head);
    if(LinkedList::tail == nullptr){LinkedList::tail = new_node;}
    LinkedList::size++;
    return *new_node;
    }
    
SQNode LinkedList::insert_tail(int value){
    SQNode* new_node = new SQNode(value);
    if(LinkedList::isEmpty()){
        LinkedList::head = new_node;
        LinkedList::tail = new_node;
        }else{
            LinkedList::tail -> next = new_node;
            LinkedList::tail = new_node;
            }
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
    if (LinkedList::isEmpty()){throw empty_linkedlist_exc;}
    else{
        SQNode* removed = LinkedList::head;
        int return_value = removed -> value;
        LinkedList::head = head -> next;
        if(LinkedList::tail == removed){LinkedList::tail = nullptr;}
        delete removed;
        LinkedList::size--;
        return return_value;
        }
    }

//O(n)
int LinkedList::remove_tail(){
    if (LinkedList::isEmpty()){throw empty_linkedlist_exc;}
    else{
        SQNode* node = LinkedList::head;
        while(node -> next != LinkedList::tail){node = node -> next;}
        LinkedList::tail = node;
        int return_value = node -> next -> value;
        delete node -> next;
        LinkedList::size--;
        return return_value;
        }
    }
    
int LinkedList::peek(){return LinkedList::head -> value;}

int LinkedList::peek_tail(){return LinkedList::tail -> value;}

bool LinkedList::contains(SQNode& lookup_node){
    if (LinkedList::isEmpty()){throw empty_linkedlist_exc;}
    for(SQNode* node = LinkedList::head; node != nullptr; node = node -> next){
        if(node == &lookup_node){return true;}
        }
    return false;
    }

//searches for the first occurande
SQNode LinkedList::search(int value){
    SQNode* node;
    for(node = LinkedList::head; node != nullptr || node -> value != value; node = node -> next);
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
    
int LinkedList::remove(SQNode& to_remove){
    SQNode* node = LinkedList::head;
    if(node == &to_remove){return LinkedList::remove_head();}
    while(node -> next != nullptr || node -> next != &to_remove){node = node -> next;}
    if(node -> next == nullptr){return NULL;}
    SQNode* to_del = node -> next;
    int return_value = to_del -> value;
    node -> next = node -> next -> next;
    delete to_del;
    return return_value;
    }
    
//Insert after a node
//O(n)
SQNode LinkedList::insert_after(SQNode& prev_node, int new_value){
    if(!LinkedList::contains(prev_node)){return NULL;}
    else{
        prev_node.next = new SQNode(new_value, prev_node.next);
        LinkedList::size++;
        return *(prev_node.next);
        }
    }
    
SQNode LinkedList::insert_after(int prev_value, int new_value){
    SQNode* node;
    for(node = LinkedList::head; node != nullptr || node -> value != prev_value; node = node -> next);
    if(node == nullptr){return NULL;}
    else{
        node -> next = new SQNode(new_value, node -> next);
        LinkedList::size++;
        return *(node -> next);
        }
    }

//Insert before node
SQNode LinkedList::insert_before(SQNode& next_node, int new_value){
    SQNode* node;
    for(node = LinkedList::head; node -> next != &next_node || node -> next != nullptr; node = node -> next);
    if(node -> next == nullptr){return NULL;}
    else{
        node -> next = new SQNode(new_value, node -> next);
        LinkedList::size++;
        return *(node -> next);
        }
    }
    
//Insert before the first occurance of a value
SQNode LinkedList::insert_before(int next_value, int new_value){
    SQNode* node;
    for(node = LinkedList::head; node -> next -> value != next_value || node -> next != nullptr; node = node -> next);
    if(node -> next == nullptr){return NULL;}
    else{
        node -> next = new SQNode(new_value, node -> next);
        LinkedList::size++;
        return *(node -> next);
        }
    }

//Insert at index
SQNode LinkedList::insert_at(int index, int new_value){
    if(index > size -1){return NULL;}
    if(index == 0){return LinkedList::insert_head(new_value);}
    SQNode* node = LinkedList::head;
    for(int i = 0; i < index; i++){node = node -> next;}
    node -> next = new SQNode(new_value, node -> next);
    LinkedList::size++;
    return *(node -> next);
    }
    
    
void LinkedList::invert(){
        if(LinkedList::size > 1){
        SQNode* previous = LinkedList::head;
        SQNode* current = previous -> next;
        SQNode* following = current -> next;
        LinkedList::head -> next -> next = LinkedList::head;
        LinkedList::head -> next = nullptr;
        while(following != nullptr){
            current -> next = previous;
            previous = current;
            current = following;
            following = following -> next;
            }
        SQNode* temp = LinkedList::tail;
        LinkedList::tail = LinkedList::head;
        LinkedList::head = temp;
        }
    }


int LinkedList::remove_after(SQNode& node){
        if(!LinkedList::contains(node)){return NULL;}
    else{
        if(LinkedList::size >= 2){
            int to_ret = node.value;
            node.next = node.next -> next;
            LinkedList::size++;
            return to_ret;
            }
        else{return NULL;}
        }
    }

int LinkedList::remove_last(int value){
    SQNode* prev_rem = nullptr;
    SQNode* prev;
    for(prev = LinkedList::head; prev -> next != nullptr; prev =  prev -> next){
        if(prev -> next -> value == value){prev_rem = prev;}
        }
    if(prev_rem == nullptr){
        if(LinkedList::head -> value == value){
            return LinkedList::remove_head();
            }else{return NULL;}
        }else{
            SQNode* to_del = prev_rem -> next;
            if(to_del == LinkedList::tail){return LinkedList::remove_tail();}
            int return_value = to_del -> value;
            prev_rem -> next = prev_rem -> next -> next;
            return return_value;
            }
    }
