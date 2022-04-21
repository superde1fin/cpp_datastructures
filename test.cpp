#include "datastructures.hpp"
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

void test(stringstream& ss){
    ss << 123;
    }

int main(){
    //stringstream ss;
    //test(ss);
    //cout << ss.str();
    
    /*
    BinarySearchTree bst = BinarySearchTree();
    bst.insert(2);
    bst.insert(1);
    bst.insert(4);
    bst.insert(3);
    bst.insert(5);
    bst.erase(2);
    BTNode root = bst.get_root();
    cout << bst.inorder() << endl;
    cout << bst.preorder() << endl;
    cout << bst.postorder() << endl;
    */
    Stack stk = Stack();
    for(int i = 0; i < 10; i++){
        stk.push(i);
        }
        
    cout << stk.push(7).get_value();
    //cout << stk.toString();
    
    return 0;
    }
