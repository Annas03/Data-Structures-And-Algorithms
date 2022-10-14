#include <iostream>
#include "node.h"
using namespace std;

node* insertNode(node* root_Node, int val);
node* SearchNode(node* root_Node, int val);
node* deleteNode(node* root_Node, int val);
node* MaximumKeyNode(node* root_Node);
void inorder_Traversal(node* root_Node);
void preorder_Traversal(node* root_Node);
void postorder_Traversal(node* root_Node);

int main(){
    int arr[] = {8,3,1,6,7,10,14,4};
    node* root_Node;
    for(int i = 0; i<8; i++){
        root_Node = insertNode(root_Node, arr[i]);
    }
    root_Node = deleteNode(root_Node, 7);
    root_Node = deleteNode(root_Node, 6);
    inorder_Traversal(root_Node);
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
        node*& Child_Node = (Parent_Node->left_child->val == val) ? Parent_Node->left_child : Parent_Node->right_child;
        if(Parent_Node == 0){
            cout<<"Key not found"<<endl;
            return NULL;
        }
        if(Child_Node->left_child == NULL && Child_Node->right_child == NULL){
                delete Child_Node;
                Child_Node = NULL;
            }
            else if(Child_Node->left_child != NULL && Child_Node->right_child == NULL){
                temp = Child_Node->left_child;
                delete Child_Node;
                Child_Node = temp;
            }
            else if(Child_Node->right_child != NULL && Child_Node->left_child == NULL){
                temp = Child_Node->right_child;
                delete Child_Node;
                Child_Node = temp;
            }
            else if(Child_Node->left_child != NULL && Child_Node->right_child != NULL){
                int temp_val = MaximumKeyNode(Child_Node->left_child)->val;
                Child_Node = deleteNode(Child_Node, MaximumKeyNode(Child_Node->left_child)->val);
                Child_Node->val = temp_val;
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
void inorder_Traversal(node* root_Node){

    if(root_Node->left_child == NULL){
        cout<<root_Node->val<<" ";
    }
    if(root_Node->left_child != NULL){
        inorder_Traversal(root_Node->left_child);
        cout<<root_Node->val<<" ";
    }
    if(root_Node->right_child != NULL){
        inorder_Traversal(root_Node->right_child);
    }
}
void preorder_Traversal(node* root_Node){
    if(root_Node != NULL){
        cout<<root_Node->val<<" ";
        preorder_Traversal(root_Node->left_child);
        preorder_Traversal(root_Node->right_child);
    }
}
void postorder_Traversal(node* root_Node){
    if(root_Node != NULL){
        postorder_Traversal(root_Node->left_child);
        postorder_Traversal(root_Node->right_child);
        cout<<root_Node->val<<" ";
    }
}
