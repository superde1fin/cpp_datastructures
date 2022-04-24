#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//==================================================================================
class Node{
    protected:
        int value;
            Node(int);
        ~Node();
    public:
    int get_value();
    string toString();
    };
//==================================================================================
//Need to create getters and setters and make actual values private
class SQNode : public Node{
    private:
        SQNode* next;
        SQNode(int, SQNode*);
        SQNode(int);
    public:
        ~SQNode();
        SQNode get_next();
        
    friend class Stack;
    friend class Queue;
    friend class LinkedList;
    friend ostream& operator << (ostream& os, const SQNode& nd);
    friend string toString(const SQNode& nd);
    friend void initialize_node_constructors();
    };
    
//==================================================================================
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
        string toString();
    };

//==================================================================================
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
        string toString();
        
    };
    
//==================================================================================
class LinkedList{
    protected:
        SQNode* head;
        SQNode* tail;
        int size;
    public:
        LinkedList();
        LinkedList(int*);
        ~LinkedList();
        bool isEmpty();
        bool contains(SQNode&);
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
    
    
//==================================================================================
class BTNode : public Node{
    protected:
        BTNode* left;
        BTNode* right;
        BTNode(int);
        BTNode(int, BTNode*, BTNode*);
    
    public:
        ~BTNode();
        BTNode get_right();
        BTNode get_left();
    
    friend class BinarySearchTree;
    };

//==================================================================================
class BinarySearchTree{
    protected:
        BTNode* root;
    
    public:
        BinarySearchTree();
        ~BinarySearchTree();
        BTNode get_root();
        bool isEmpty();
        BTNode insert(int);
        int erase(int);
        bool validate();
        bool validate_subtree(BTNode*);
        void delete_subtree(BTNode*);
        string inorder();
        void inorder_parser(BTNode*, stringstream&);
        string preorder();
        void preorder_parser(BTNode*, stringstream&);
        string postorder();
        void postorder_parser(BTNode*, stringstream&);
    };


class HNode : public Node{
    protected:
        HNode(int);
        int height;
        HNode* parent;
        HNode* right;
        HNode* left;
        
    public:
        ~HNode();
        int get_height();
        HNode get_parent();
        HNode get_right();
        HNode get_left();
        
    friend class AVL_Tree;
    };


//==================================================================================
class AVL_Tree{
    protected:
    HNode* root;
    public:
    AVL_Tree();
    ~AVL_Tree();
    HNode insert(int);
    int erase(int);
    bool isEmpty();
    bool validate_subtree(HNode*);
    void rotate_left(HNode*);
    void rotate_right(HNode*);
    int calc_height(HNode*);
    bool update_heights(HNode*);
    void inspect_insert(HNode*);
    void inspect_delete(HNode*);
    int get_balance_factor(HNode*);
    HNode* rebalance(HNode*, HNode*, HNode*);
    HNode get_root();
    };
