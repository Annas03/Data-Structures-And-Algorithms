#include <iostream>
using namespace std;

class node{
    public:
    int val;
    node* next;
    node(){
        next = NULL;
    }
    node(int val){
        this->val = val;
        next = NULL;
    }
};

node* enqueue(node* root, int val);
node* dequeue(node* root);
void display(node* root);

int main(){
    node* root;
    root = enqueue(root, 4);
    root = enqueue(root, 6);
    root = dequeue(root);

    return 0;
}

node* enqueue(node* root, int val){
    node* temp_node;
    temp_node = root;
    root = new node(val);
    root->next = temp_node;
    return root;
}
node* dequeue(node* root){
    if(root->next != NULL){
        root->next = dequeue(root->next);
    }
    else{
        delete root;
    }
    return root;

}