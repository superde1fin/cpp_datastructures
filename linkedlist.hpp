#include "datastructures.h"
#include "datastructures.hpp"

using namespace std;

class EmptyLinkedListException: public runtime_error{
    public: EmptyLinkedListException(): runtime_error("Empty Linked List"){}
    }empty_linkedlist_exc;

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

//searches for the first occurande
SQNode LinkedList::search(int value){
    for(SQNode* node = LinkedList::head; node != nullptr || node -> value != value; node = node -> next);
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
    return return_node -> value;
    }
    
//Insert after a node
//O(n)
SQNode LinkedList::insert_after(SQNode& prev_node, int new_value){
    if(!LinkedList::contains(prev_node)){return NULL;}
    else{
        prev_node -> next = new SQNode(new_value, prev_node -> next);
        LinkedList::size++;
        return *(prev_node -> next);
        }
    }
    
SQNode LinkedList::insert_after(int prev_value, int new_value){
    for(SQNode* node = LinkedList::head; node != nullptr || node -> value != value; node = node -> next);
    if(node == nullptr){return NULL;}
    else{
        node -> next = new SQNode(new_value, node -> next);
        LinkedList::size++;
        return *(node -> next);
        }
    }

//Insert before node
SQNode LinkedList::insert_before(SQNode& next_node, int new_value){
    for(SQNode* node = LinkedList::head; node -> next != next_node || node -> next != nullptr; node = node -> next);
    if(node -> next == nullptr){return NULL;}
    else{
        node -> next = new SQNode(new_value, node -> next);
        LinkedList::size++;
        return *(node -> next);
        }
    }
    
//Insert before the first occurance of a value
SQNode LinkedList::insert_before(int next_value, int new_value){
    for(SQNode* node = LinkedList::head; node -> next -> value != next_value || node -> next != nullptr; node = node -> next);
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
    if(index == 0){LinkedList::insert_head(new_value)}
    SQNode* node = LinkedList::head;
    for(int i = 0; i < index; i++){node = node -> next;}
    node -> next = new SQNode(new_value, node -> next);
    LinkedList::size++;
    return *(node -> next);
    }
    }
    
void LinkedList::invert(){
        if(LinkedList::size > 1){
        SQNode* previous = LinkedList::head;
        current = previous -> next;
        following = current -> next;
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
            node -> next = node -> next -> next
            LinkedList::size++;
            return *(prev_node -> next);
            }
        else{return NULL;}
        }
    }

int LinkedList::remove_last(int value){
    SQNode* prev_rem = nullptr;
    for(SQNode* prev = LinkedList::head; prev -> next != nullptr; prev =  prev -> next){
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
