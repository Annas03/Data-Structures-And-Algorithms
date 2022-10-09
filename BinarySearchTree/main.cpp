#include <iostream>
#include "node.h"
using namespace std;

node* insertNode(node* root_Node, int val);
void deleteNode();

int main(){
    int arr[] = {4,2,3,6,5,7,1};
    node* root_Node;
    for(int i = 0; i<7; i++){
        root_Node = insertNode(root_Node, arr[i]);
    }
    cout<<root_Node->right_child->val<<endl;
    return 0;
}

node* insertNode(node* root_Node, int val){
    if(root_Node == NULL){
        root_Node = new node(val);
        return root_Node;
    }
    else if(root_Node->val > val){
        root_Node->left_child = insertNode(root_Node->left_child, val); 
    }
    else if(root_Node->val < val){
        root_Node->right_child = insertNode(root_Node->right_child, val);
    }
    return root_Node;
}

// void deleteNode(){

// }
