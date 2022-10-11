#include <iostream>
#include "node.h"
using namespace std;

node* insertNode(node* root_Node, int val);
node* SearchNode(node* root_Node, int val);
node* deleteNode(node* root_Node, int val);
node* MaximumKeyNode(node* root_Node);

int main(){
    int arr[] = {4,2,3,6,5,7,1};
    node* root_Node;
    for(int i = 0; i<7; i++){
        root_Node = insertNode(root_Node, arr[i]);
    }
    root_Node = deleteNode(root_Node,4);
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
    node* temp;
    if(root_Node->val != val){
        node* Parent_Node = SearchNode(root_Node, val);
        if(Parent_Node == 0){
            cout<<"Key not found"<<endl;
            return NULL;
        }
        if(Parent_Node->left_child->val == val){
            if(Parent_Node->left_child->left_child == NULL && Parent_Node->left_child->right_child == NULL){
                delete Parent_Node->left_child;
                Parent_Node->left_child = NULL;
            }
            else if(Parent_Node->left_child->left_child != NULL && Parent_Node->left_child->right_child == NULL){
                temp = Parent_Node->left_child->left_child;
                delete Parent_Node->left_child;
                Parent_Node->left_child = temp;
            }
            else if(Parent_Node->left_child->right_child != NULL && Parent_Node->left_child->left_child == NULL){
                temp = Parent_Node->left_child->right_child;
                delete Parent_Node->left_child;
                Parent_Node->left_child = temp;
            }
            else if(Parent_Node->left_child->left_child != NULL && Parent_Node->left_child->right_child != NULL){
                int temp_val = MaximumKeyNode(Parent_Node->left_child->left_child)->val;
                Parent_Node->left_child = deleteNode(Parent_Node->left_child, MaximumKeyNode(Parent_Node->left_child->left_child)->val);
                Parent_Node->left_child->val = temp_val;
            }
        }
        else if(Parent_Node->right_child->val == val){
            if(Parent_Node->right_child->left_child == NULL && Parent_Node->right_child->right_child == NULL){
                delete Parent_Node->right_child;
                Parent_Node->right_child = NULL;
            }
            else if(Parent_Node->right_child->left_child != NULL && Parent_Node->right_child->right_child == NULL){
                temp = Parent_Node->right_child->left_child;
                delete Parent_Node->right_child;
                Parent_Node->right_child = temp;
            }
            else if(Parent_Node->right_child->right_child != NULL && Parent_Node->right_child->left_child == NULL){
                temp = Parent_Node->right_child->right_child;
                delete Parent_Node->right_child;
                Parent_Node->right_child = temp;
            }
            else if(Parent_Node->right_child->left_child != NULL && Parent_Node->right_child->right_child != NULL){
                int temp_val = MaximumKeyNode(Parent_Node->right_child->left_child)->val;
                Parent_Node->right_child = deleteNode(Parent_Node->right_child, MaximumKeyNode(Parent_Node->right_child->left_child)->val);
                Parent_Node->right_child->val = temp_val;
            }
        }
    }
    else{
        if(root_Node->left_child == NULL && root_Node->right_child == NULL){
            delete root_Node;
            root_Node = NULL;
        }
        else if(root_Node->left_child != NULL && root_Node->right_child == NULL){
            temp = root_Node->left_child;
            delete root_Node;
            root_Node = temp;
        }
        else if(root_Node->right_child != NULL && root_Node->left_child == NULL){
            temp = root_Node->right_child;
            delete root_Node;
            root_Node = temp;
        }
        else if(root_Node->left_child != NULL && root_Node->right_child != NULL){
            int temp_val = MaximumKeyNode(root_Node->left_child)->val;
            root_Node = deleteNode(root_Node, MaximumKeyNode(root_Node->left_child)->val);
            root_Node->val = temp_val;
        }
    }
    
    return root_Node;
}
node* MaximumKeyNode(node* root_Node){
    while(root_Node->right_child != NULL){
        root_Node = root_Node->right_child;
    }
    return root_Node;
}
