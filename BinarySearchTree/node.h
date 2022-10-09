#include <iostream>
using namespace std;

class node{
    public:
        int val;
        node *left_child;
        node *right_child;

        node(int val){
            this->val = val;
            this->left_child = NULL;
            this->right_child = NULL;
        }
        node(){
            this->left_child = NULL;
            this->right_child = NULL;
        }
        // ~node(){
        //     delete left_child, right_child;
        // }
};
