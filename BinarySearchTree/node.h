#include <iostream>
using namespace std;

class node{
    public:
        int val;
        node *left_child;
        node *right_child;

        node(int val){
            this->val = val;
            left_child = NULL;
            right_child = NULL;
        }
        void insertNode(node* root_Node, int val){
            if(root_Node.val > val){
               insertNode(root_Node.left_child, val); 
            }
            else if(root_Node.val < val){
                insertNode(root_Node.right_child, val);
            }
        }
};