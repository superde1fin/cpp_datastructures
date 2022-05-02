#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <openssl/sha.h>
#include <math.h>
#include <gmpxx.h>
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
    
class EmptyHeapException: public runtime_error{
    public: EmptyHeapException(): runtime_error("Empty Heap"){}
    }empty_heap_exc;
    
class WrongKeyException: public runtime_error{
    public: WrongKeyException(): runtime_error("Key does not exist"){}
    }wrong_key_exc;
    
    
//Node
//==================================================================================
Node::Node(int new_value){
    Node::value = new_value;
    }
    
Node::~Node(){
    Node::value = NULL;
    }
    
string Node::toString(){
    stringstream ss;
    ss << Node::value;
    return ss.str();
    }

int Node::get_value(){return Node::value;}

//Stack - Queue Node (also used for Linked Lists)
//==================================================================================
SQNode::SQNode(int input_value, SQNode* next) : Node(input_value){
    SQNode::next = next;
    }
SQNode::SQNode(int input_value) : Node(input_value){
    SQNode::next = nullptr;
    }
SQNode::~SQNode(){
    SQNode::next = nullptr;
    }
    
SQNode SQNode::get_next(){return *SQNode::next;}

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
    
string Stack::toString() {
        string result = "Top -> ";
        SQNode* node = Stack::head;
        while(node){
            result = result + "[" + node -> toString() + "]";
            node = node -> next;
        }
        result += " <- Bottom";
        return result;
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

string Queue::toString() {
        string result = "Front -> ";
        SQNode* node = Queue::front;
        while(node){
            result = result + "[" + node -> toString() + "]";
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
BTNode::BTNode(int new_value) : Node(new_value){
    BTNode::left = nullptr;
    BTNode::right = nullptr;
    }
    
//Need to make it impossible to pass variables without their names
//BTNode::BTNode(int new_value, BTNode* left, BTNode* right){
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
    
//Height Node for AVL Trees
//==================================================================================
HNode::HNode(int new_value) : Node(new_value){
    HNode::right = nullptr;
    HNode::left = nullptr;
    HNode::height = 1;
    HNode::parent = nullptr;
    }   
    
HNode::~HNode(){
    HNode::height = NULL;
    HNode::parent = nullptr;
    }
    
HNode HNode::get_right(){return *HNode::right;}
HNode HNode::get_left(){return *HNode::left;}
HNode HNode::get_parent(){return *HNode::parent;}
int HNode::get_height(){return HNode::height;}
    
    
//AVL Tree
//==================================================================================

HNode AVL_Tree::get_root(){return *AVL_Tree::root;}

AVL_Tree::AVL_Tree() {
    AVL_Tree::root = nullptr;
    }
    
AVL_Tree::~AVL_Tree(){
    AVL_Tree::root = nullptr;
    }

//Standart AVL rotation where x, y, z are child, parent, and great parent respectively
void AVL_Tree::rotate_left(HNode* x){
    HNode* y = x -> parent;
    HNode* z = y -> parent;
    y -> right = x -> left;
    x -> left = y;
    if(z != nullptr){
        if(y == z -> left){z -> left = x;}
        else{z -> right = x;}
        }
    }

void AVL_Tree::rotate_right(HNode* x){
    HNode* y = x -> parent;
    HNode* z = y -> parent;
    y -> left = x -> right;
    x -> right = y;
    if(z != nullptr){
        if(y == z -> left){z -> left = x;}
        else{z -> right = x;}
        }
    }

int AVL_Tree::calc_height(HNode* node){
    if(node -> right != nullptr && node -> left != nullptr){
        return node -> right -> height > node -> left -> height ? node -> right -> height +1 : node -> left -> height + 1;
        }
    if(node -> right == nullptr && node -> left != nullptr){return node -> left -> height +1;}
    if(node -> right != nullptr && node -> left == nullptr){return node -> right -> height + 1;}
    if(node -> right == nullptr && node -> left == nullptr){return 1;}
    }
    
HNode AVL_Tree::insert(int new_value){
    HNode* new_node = new HNode(new_value);
    if(AVL_Tree::isEmpty()){
        AVL_Tree::root = new_node;
        return *AVL_Tree::root;
        }
    
    HNode* node = AVL_Tree::root;
    bool placed = false;
    while(!placed){
        if(new_value >= node -> value){
            if(node -> right != nullptr){
                node = node -> right;
                }else{
                    //If no node than place new
                    node -> right = new_node;
                    new_node -> parent = node;
                    placed = true;
                    }
            }else{
                if(node -> left != nullptr){
                    node = node -> left;
                    }else{
                        node -> left = new_node;
                        new_node -> parent = node;
                        placed = true;
                        }
                }
        }
        
    AVL_Tree::inspect_insert(new_node);
    return *new_node;
    }

int AVL_Tree::get_balance_factor(HNode* node){
    return (node -> left != nullptr ? node -> left -> height : 0) - (node -> right != nullptr ? node -> right -> height : 0);
    }

void AVL_Tree::inspect_insert(HNode* node){
    HNode* parent = node -> parent;
    HNode* gparent = parent -> parent;
    parent -> height++;
    int old_gparent_height;
    
    bool rebalanced = false;
    do{
        old_gparent_height = gparent -> height;
        if(AVL_Tree::get_balance_factor(gparent) > 1){
            rebalanced = AVL_Tree::rebalance(gparent, parent, node);
            continue;
            }else{
                AVL_Tree::calc_height(gparent);
                }
        gparent = gparent -> parent;
        parent = parent -> parent;
        node = node ->parent;
        }while(!rebalanced && gparent != nullptr && old_gparent_height != parent -> height);
    
    

    }

HNode* AVL_Tree::rebalance(HNode* gparent, HNode* parent, HNode* node){
    if(parent = gparent -> left){
        if(node = parent -> left){
            //Left left case
            AVL_Tree::rotate_right(parent);
            parent -> height = AVL_Tree::calc_height(parent);
            return parent;
            }else{
                //Left right case
                AVL_Tree::rotate_left(node);
                AVL_Tree::rotate_right(node); 
                node -> height = AVL_Tree::calc_height(node);
                return node;
                }
        }else{
            if(node = parent -> left){
            //Right left case
                AVL_Tree::rotate_right(node);
                AVL_Tree::rotate_left(node); 
                node -> height = AVL_Tree::calc_height(node);
                return node;
            }else{
                //Right right case
                AVL_Tree::rotate_left(parent); 
                parent -> height = AVL_Tree::calc_height(parent);
                return parent;
                }
            }
    }

int AVL_Tree::erase(int erase_value){
    if(AVL_Tree::isEmpty()){return -1;}
    HNode* updated_node;
    HNode* parent = AVL_Tree::root;
    HNode* node = parent;
    bool is_left;
    bool deleted = false;
    while(deleted == 0 && node != nullptr){
        //If found node check for four conditions has left, has right, has both, or has niether 
        if(node -> value == erase_value){
            //Has both
            if(node -> right != nullptr && node -> left != nullptr){
                updated_node = parent;
                //Finding successor from the right (smallest value)
                HNode* successor;
                for(successor = node -> right; successor -> left != nullptr; successor = successor -> left){
                    parent = successor;
                    }
                //Copy successor's value to the node that has to be removed
                node -> value = successor -> value;
                //Set node to successor for further checks to remove it
                node = successor;
                is_left = true;
                }
            //Has niether (leaf)
            if(node -> right == nullptr && node -> left == nullptr){
                updated_node = parent;
                //No need to reparent if deleting a root
                if(node != AVL_Tree::root){
                    if(is_left){parent -> left = nullptr;}else{parent -> right = nullptr;}
                    }
                delete node;
                deleted = true;
                continue;
                }
            //Has left
            if(node -> right == nullptr && node -> left != nullptr){
                updated_node = parent;
                if(node != AVL_Tree::root){
                    //Connecting node -> left to a parent
                    if(is_left){parent -> left = node -> left;}else{parent -> right = node -> left;}
                    }
                delete node;
                deleted = true;
                continue;
                }
            //Has right
            if(node -> right != nullptr && node -> left == nullptr){
                updated_node = parent;
                if(node != AVL_Tree::root){
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
        
    AVL_Tree::inspect_delete(updated_node);
    return 0;
    }

void AVL_Tree::inspect_delete(HNode* node){
    int old_height;
    HNode* y;
    HNode* x;
    
    do{
        old_height = node -> height;
        if(AVL_Tree::get_balance_factor(node) > 1){
            y = node -> left;
            x = AVL_Tree::get_balance_factor(y) <=0 ? y -> right : y -> left;
            node = AVL_Tree::rebalance(node, y, x);
            } 
        if(AVL_Tree::get_balance_factor(node) < -1){
            y = node -> right;
            x = AVL_Tree::get_balance_factor(y) <=0 ? y -> right : y -> left;
            node = AVL_Tree::rebalance(node, y, x);
            }
        if(AVL_Tree::get_balance_factor(node) >= -1 && AVL_Tree::get_balance_factor(node) <= 1){
            node -> height = AVL_Tree::calc_height(node);
            }
        }while(node != nullptr && node -> height != old_height);
    }

bool AVL_Tree::isEmpty(){
    return AVL_Tree::root == nullptr;
    }
    
//Item
//==================================================================================
Item::Item(int id, int value){
    Item::id = id;
    Item::value = value;
    }

Item::Item(){
    Item::id = NULL;
    Item::value = NULL;
    }
    
//Heap
//==================================================================================
Heap::Heap(){}

int Heap::get_left_index(int index){
    return 2*index + 1;
    }

int Heap::get_right_index(int index){
    return 2*index + 2;
    }

int Heap::get_parent_index(int index){
    return (int)(index - 1)/2;
    }
    
int Heap::length(){
    return Heap::heap.size();
    }
    
string Heap::toString(){
    string result = "[";
    stringstream ss;
    for(int i = 0; i < Heap::length() - 1; i++){
        ss.str(string());
        ss << Heap::heap[i].id << ":" << Heap::heap[i].value;
        result += ss.str() + ", ";
        }
    ss.str(string());
    ss << Heap::heap[Heap::length() - 1].id << ":" << Heap::heap[Heap::length() - 1].value;
    result += ss.str() + "]";
    return result;
    }

//Min Heap
//==================================================================================
MinHeap::MinHeap() : Heap(){}

int MinHeap::get_min(){
    if(MinHeap::length() == 0){
        throw empty_heap_exc;
        }else{
            return MinHeap::heap[0].value;
            }
    }

int MinHeap::extract_min(){
    if(MinHeap::length() == 0){
        throw empty_heap_exc;
        }
        
    int value = MinHeap::heap[0].value;
    if(MinHeap::length() > 1){
        Item last_element = MinHeap::heap[MinHeap::length() - 1];
        MinHeap::heap[0] = last_element;
        MinHeap::heap.pop_back();
        MinHeap::swift_down(0);
        }else{
            MinHeap::heap.clear();
            }
    return value;
    }

void MinHeap::swift_down(int index){
        int left, right, swap_index, swap_left, swap_right;
         
        bool done = false;
        while(!done){
            left = get_left_index(index);
            right = get_right_index(index);
            swap_index = -1;
            swap_left = -1;
            swap_right = -1;
            if(left < MinHeap::length() && MinHeap::heap[index].id > MinHeap::heap[left].id){swap_left = left;}
            if(right < MinHeap::length() && MinHeap::heap[index].id > MinHeap::heap[right].id){swap_right = right;}
            if(swap_left < 0 && swap_right < 0){
                done = true;
                continue;
                }
            
            if(swap_left > 0 && swap_right > 0){
                if(MinHeap::heap[left].id < MinHeap::heap[right].id){swap_index = left;}
                else{swap_index = right;}
            }else{swap_index = swap_left >swap_right ? swap_left : swap_right;}
            
            Item temp = MinHeap::heap[index];
            MinHeap::heap[index] = MinHeap::heap[swap_index];
            MinHeap::heap[swap_index] = temp;
            index = swap_index;
        }
    }

void MinHeap::insert(int value, int id){
        MinHeap::heap.push_back(Item(id, value));
        int index = MinHeap::length() - 1;
        int parent = get_parent_index(index);
        Item temp;
        while(MinHeap::heap[parent].id > MinHeap::heap[index].id && parent >= 0){
            temp = MinHeap::heap[index];
            MinHeap::heap[index] = MinHeap::heap[parent];
            index = parent;
            parent = get_parent_index(index);
        }
    }
    
    
void MinHeap::build_heap(int array[], int size){
    for(int i = 0; i < size; i++){
        MinHeap::heap.push_back(Item(i, array[i]));
        }
    int last_index = MinHeap::length() - 1;
    for(int i = MinHeap::get_parent_index(last_index); i >= 0; i--){
        MinHeap::swift_down(i);
        }
    }


//Max Heap
//==================================================================================
MaxHeap::MaxHeap() : Heap(){}

int MaxHeap::get_max(){
    if(MaxHeap::length() == 0){
        throw empty_heap_exc;
        }else{
            return MaxHeap::heap[0].value;
            }
    }

int MaxHeap::extract_max(){
    if(MaxHeap::length() == 0){
        throw empty_heap_exc;
        }
        
    int value = MaxHeap::heap[0].value;
    if(MaxHeap::length() > 1){
        Item last_element = MaxHeap::heap[MaxHeap::length() - 1];
        MaxHeap::heap[0] = last_element;
        MaxHeap::heap.pop_back();
        MaxHeap::swift_down(0);
        }else{
            MaxHeap::heap.clear();
            }
    return value;
    }

void MaxHeap::swift_down(int index){
        int left, right, swap_index, swap_left, swap_right;
         
        bool done = false;
        while(!done){
            left = get_left_index(index);
            right = get_right_index(index);
            swap_index = -1;
            swap_left = -1;
            swap_right = -1;
            if(left < MaxHeap::length() && MaxHeap::heap[index].id < MaxHeap::heap[left].id){swap_left = left;}
            if(right < MaxHeap::length() && MaxHeap::heap[index].id < MaxHeap::heap[right].id){swap_right = right;}
            if(swap_left < 0 && swap_right < 0){
                done = true;
                continue;
                }
            
            if(swap_left > 0 && swap_right > 0){
                if(MaxHeap::heap[left].id > MaxHeap::heap[right].id){swap_index = left;}
                else{swap_index = right;}
            }else{swap_index = swap_left >swap_right ? swap_left : swap_right;}
            
            Item temp = MaxHeap::heap[index];
            MaxHeap::heap[index] = MaxHeap::heap[swap_index];
            MaxHeap::heap[swap_index] = temp;
            index = swap_index;
        }
    }

void MaxHeap::insert(int value, int id){
        MaxHeap::heap.push_back(Item(id, value));
        int index = MaxHeap::length() - 1;
        int parent = get_parent_index(index);
        Item temp;
        while(MaxHeap::heap[parent].id < MaxHeap::heap[index].id && parent >= 0){
            temp = MaxHeap::heap[index];
            MaxHeap::heap[index] = MaxHeap::heap[parent];
            index = parent;
            parent = get_parent_index(index);
        }
    }
    
    
void MaxHeap::build_heap(int array[], int size){
    for(int i = 0; i < size; i++){
        MaxHeap::heap.push_back(Item(i, array[i]));
        }
    int last_index = MaxHeap::length() - 1;
    for(int i = MaxHeap::get_parent_index(last_index); i >= 0; i--){
        MaxHeap::swift_down(i);
        }
    }


//String Item
//==================================================================================
StringItem::StringItem(string key,  int value){
    StringItem::key = key;
    StringItem::value = value;
    StringItem::empty = false;
    }
    
StringItem::StringItem(){
    StringItem::empty = true;
    }
    
string StringItem::get_key(){return StringItem::key;}
int StringItem::get_value(){return StringItem::value;}

//HashTable
//==================================================================================
HashTable::HashTable(int size){
    HashTable::size = size;
    HashTable::item_num = 0;
    for(int i = 0; i < size; i++){
        HashTable::array.push_back(StringItem());
        }
    }
    
HashTable::HashTable(){
    HashTable::size = 10;
    HashTable::item_num = 0;
    for(int i = 0; i < size; i++){
        HashTable::array.push_back(StringItem());
        }
    }

int HashTable::hash_function(const string str){
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);
    stringstream ss;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }
    string result = ss.str();
    mpz_class hash_num = 0;
    for(int i = 0; i < result.length(); i++){
        int ascii_value = int(result[i]);
        ss.str("");
        ss << ascii_value;
        hash_num = hash_num*int(pow(10, ss.str().length())) + ascii_value;
        }
    return hash_num.get_ui()% HashTable::size;
    }

int HashTable::get_index(string key){
    int index = HashTable::hash_function(key);
    for(int i = 0; i < HashTable::size; i ++){
        StringItem item = HashTable::array[index];
        if(!item.empty && !HashTable::deleted[index]){return NULL;}
        else{if(!item.empty && item.key == key){return index;}
            else{index = (index + 1) % HashTable::size;}
            }
        }
    }
    
void HashTable::set(string key, int value){
    int index = HashTable::hash_function(key);
    int i = 0;
    bool done = false;    
    while(!done && i < HashTable::size){
        //Empty undeleted slot
        if(HashTable::array[index].empty && !HashTable::deleted[index]){
            HashTable::array[index] = StringItem(key, value);
            HashTable::item_num ++;
            done = true;
            continue;
        }
        //Empty deleted slot
        else{
        if(HashTable::array[index].empty && HashTable::deleted[index]){
            int existing_index = HashTable::get_index(key);
            if(existing_index == NULL){
                HashTable::array[index] = StringItem(key, value);
                HashTable::item_num ++;
            }
            else{
                HashTable::array[existing_index].value = value;
            }
            done = true;
            continue;
        }
        //Full slot desired key
        else{
        if(HashTable::array[index].key == key){
            HashTable::array[index].value = value;
            done = true;
            continue;
        }
        //Different key
        else{
            index = (index + 1) % HashTable::size;
        }
            }
        }
    i ++;
    }
                    
    if(HashTable::item_num > 0.9*HashTable::size){
        //HashTable::resize();
    }
    }
    
int HashTable::get(string key){
    int index = HashTable::get_index(key);
    if(index != NULL){
        return HashTable::array[index].value;
        }
    else{
        throw wrong_key_exc;
        }
    }

void HashTable::del(string key){
    int index = HashTable::get_index(key);
    if(index != NULL){
        delete &HashTable::array[index] ;
        HashTable::array[index].empty = true;
        HashTable::deleted[index] = true;
        HashTable::item_num--;
        }
    else{
        throw wrong_key_exc;
        }
    }

bool HashTable::in(string key){return HashTable::get_index(key) != NULL;}



