#include <iostream>
#include "node.h"
using namespace std;

node* insertNode(node* root_Node, int val);
node* SearchNode(node* root_Node, int val);
node* deleteNode(node* root_Node, int val);

int main(){
    int arr[] = {4,2,3,6,5,7,1};
    node* root_Node;
    for(int i = 0; i<7; i++){
        root_Node = insertNode(root_Node, arr[i]);
    }
    root_Node = deleteNode(root_Node,1);
    cout<<root_Node->left_child->left_child<<endl;
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

node* SearchNode(node* root_Node,int val){
    while(root_Node != NULL){
        if(root_Node->left_child->val == val || root_Node->right_child->val == val){
            return root_Node;
        }
        else if(root_Node->val > val){
            root_Node = root_Node->left_child;
        }
        else if(root_Node->val < val){
            root_Node = root_Node->right_child;
        }
    }
    return NULL;
}

node* deleteNode(node* root_Node, int val){
    node* Parent_Node = SearchNode(root_Node, val);
    node* child_Node;
    if(Parent_Node == 0){
        cout<<"Key not found"<<endl;
        return NULL;
    }
    if(Parent_Node->left_child->val == val){
        if(Parent_Node->left_child->left_child == NULL && Parent_Node->left_child->right_child == NULL){
            delete Parent_Node->left_child;
            Parent_Node->left_child = NULL;
        }
    }
    else if(Parent_Node->right_child->val == val){
        if(Parent_Node->right_child->left_child == NULL && Parent_Node->right_child->right_child == NULL){
            delete Parent_Node->right_child;
            Parent_Node->right_child = NULL;
        }
    }

    return root_Node;
}
