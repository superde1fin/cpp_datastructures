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

//BInary Tree Node
//==================================================================================
BTNode::BTNode(int new_value){
    BTNode::value = new_value;
    BTNode::left = nullptr;
    BTNode::right = nullptr;
    }
    
//Need to make it impossible to pass variables without their names
//BTNode::BTNode(int new_value, BTNode* left, BTNode* right){
    //BTNode::value = new_value;
    //BTNode::left = left;
    //BTNode::right = right;
    //}
    
BTNode::~BTNode(){
    BTNode::value = NULL;
    BTNode::left = nullptr;
    BTNode::right = nullptr;
    }
    
BTNode BTNode::get_right(){return *BTNode::right;}
BTNode BTNode::get_left(){return *BTNode::left;}
int BTNode::get_value(){return BTNode::value;}

//Binary Search Tree
//==================================================================================
BinarySearchTree::BinarySearchTree(){
    BinarySearchTree::root = nullptr;
    }
    
void BinarySearchTree::delete_subtree(BTNode* root){
    if(root != nullptr){
        BinarySearchTree::delete_subtree(root -> left);
        root -> left = nullptr;
        BinarySearchTree::delete_subtree(root -> left);
        root -> left = nullptr;
        root -> value = NULL;
        }
    }
    
BTNode BinarySearchTree::get_root(){return *BinarySearchTree::root;}
    
BinarySearchTree::~BinarySearchTree(){
    BinarySearchTree::delete_subtree(BinarySearchTree::root);
    }
    
bool BinarySearchTree::validate_subtree(BTNode* root){
    if(root != nullptr){
        bool is_valid = true;
        if(root -> right != nullptr && root -> left != nullptr){
            is_valid = (root -> left -> value <= root -> value) && (root -> right -> value >= root -> value);
            }
        if(root -> right == nullptr && root -> left != nullptr){
            is_valid = (root -> left -> value <= root -> value) ;
            }
        if(root -> right != nullptr && root -> left == nullptr){
            is_valid = (root -> right-> value >= root -> value) ;
            }
            
        return is_valid && validate_subtree(root -> left) && validate_subtree(root -> right);
        }
    else{return true;}
    }

bool BinarySearchTree::validate(){
    return BinarySearchTree::validate_subtree(BinarySearchTree::root);
}

bool BinarySearchTree::isEmpty(){
    return BinarySearchTree::root == nullptr;
    }

BTNode BinarySearchTree::insert(int new_value){
    BTNode* new_node = new BTNode(new_value);
    if(BinarySearchTree::isEmpty()){
        BinarySearchTree::root = new_node;
        return *BinarySearchTree::root;
        }
    BTNode* node = BinarySearchTree::root;
    bool placed = false;
    while(!placed){
        if(new_value >= node -> value){
            if(node -> right != nullptr){
                node = node -> right;
                }else{
                    //If no node than place new
                    node -> right = new_node;
                    placed = true;
                    }
            }else{
                if(node -> left != nullptr){
                    node = node -> left;
                    }else{
                        node -> left = new_node;
                        placed = true;
                        }
                }
        }
    return *new_node;
    }


int BinarySearchTree::erase(int erase_value){
    if(BinarySearchTree::isEmpty()){return -1;}
    BTNode* parent = BinarySearchTree::root;
    BTNode* node = parent;
    bool is_left;
    bool deleted = false;
    while(deleted == 0 && node != nullptr){
        //If found node check for four conditions has left, has right, has both, or has niether 
        if(node -> value == erase_value){
            //Has both
            if(node -> right != nullptr && node -> left != nullptr){
                //Finding successor from the right (smallest value)
                BTNode* successor;
                for(successor = node -> right; successor -> left != nullptr; successor = successor -> left){
                    parent = successor;
                    }
                //Copy successor's value to the node that has to be removed
                node -> value = successor -> value;
                //Set node to successor for further checks to remove it
                node = successor;
                is_left = true;
                //BinarySearchTree::inorder(BinarySearchTree::root);
                //continue;
                }
            //Has niether (leaf)
            if(node -> right == nullptr && node -> left == nullptr){
                //No need to reparent if deleting a root
                if(node != BinarySearchTree::root){
                    if(is_left){parent -> left = nullptr;}else{parent -> right = nullptr;}
                    }
                delete node;
                deleted = true;
                continue;
                }
            //Has left
            if(node -> right == nullptr && node -> left != nullptr){
                if(node != BinarySearchTree::root){
                    //Connecting node -> left to a parent
                    if(is_left){parent -> left = node -> left;}else{parent -> right = node -> left;}
                    }
                delete node;
                deleted = true;
                continue;
                }
            //Has right
            if(node -> right != nullptr && node -> left == nullptr){
                if(node != BinarySearchTree::root){
                    //Connecting node -> right to a parent
                    if(is_left){parent -> left = node -> right;}else{parent -> right = node -> right;}
                    }
                delete node;
                deleted = true;
                continue;
                }
            }
        if(!deleted){
            //Check if value is smaller than node and go left
            if(erase_value < node -> value){
                parent = node;
                node = node -> left;
                is_left = true;
                }
                
            //Check if value is greater than node and go right
            if(erase_value > node -> value){
                parent = node;
                node = node -> right;
                is_left = false;
                }
            }
        }
    return 0;
    }

void BinarySearchTree::inorder_parser(BTNode* root, stringstream& ss){
    if(root != nullptr){
        BinarySearchTree::inorder_parser(root -> left, ss);
        ss << '[' << root -> value << ']';
        BinarySearchTree::inorder_parser(root -> right, ss);
    }
    }

string BinarySearchTree::inorder(){
    stringstream ss;
    inorder_parser(BinarySearchTree::root, ss);
    return ss.str();
    }

void BinarySearchTree::preorder_parser(BTNode* root, stringstream& ss){
    if(root != nullptr){
        ss << '[' << root -> value << ']';
        BinarySearchTree::preorder_parser(root -> left, ss);
        BinarySearchTree::preorder_parser(root -> right, ss);
    }
    }

string BinarySearchTree::preorder(){
    stringstream ss;
    preorder_parser(BinarySearchTree::root, ss);
    return ss.str();
    }
    
void BinarySearchTree::postorder_parser(BTNode* root, stringstream& ss){
    if(root != nullptr){
        BinarySearchTree::postorder_parser(root -> left, ss);
        BinarySearchTree::postorder_parser(root -> right, ss);
        ss << '[' << root -> value << ']';
    }
    }

string BinarySearchTree::postorder(){
    stringstream ss;
    postorder_parser(BinarySearchTree::root, ss);
    return ss.str();
    }

