#include <iostream>
using namespace std;

class node{
    public:
    int key;
    node* next;
    node(){
        next = NULL;
    }
    node(int val){
        this->key = val;
        next = NULL;
    }
};