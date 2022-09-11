# include <iostream>
using namespace std;

// Each entry in a Linked list is called a Node. A node contains a key/value and the address of next node.

class node{
    public:
        int val;
        node* next;

        node(int val){
            this->val = val;
            next = NULL;
        }
};

void AddNodeToLast(node* &head, int val){
    node* n = new node(val);

    if(head == NULL){
        head = n;
        return;
    }

    node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}

void AddNodeToStart(node* &head, int val){
    node* n = new node(val);
    node* temp = head;
    head = n;
    head->next = temp;
}

void display(node* h_ptr){
    node* temp = h_ptr;
    while(temp != NULL){
        cout<<temp->val<<" -> ";
        temp = temp->next;
    }
}

int main(){
    node* head = NULL;
    AddNodeToLast(head, 1);
    AddNodeToLast(head, 2);
    AddNodeToStart(head, 5);
    AddNodeToLast(head, 3);
    AddNodeToStart(head, 4);
    display(head);
}