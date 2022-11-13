#include<iostream>
#include"node.h"
using namespace std;

class HashTable{
    public:
    int hash_size, hash_index;
    node* hash_table;
    HashTable();
    void Insert(int* arr, int lenght);
    void display();
};

HashTable::HashTable(){
    hash_size = 10;
    hash_table = new node[hash_size];
}
void HashTable::Insert(int* arr, int lenght){
    for(int i=0; i<lenght; i++){
        hash_index = arr[i]%hash_size;
        if(hash_table[hash_index].next == NULL)
        {
            node* n = new node(arr[i]);
            hash_table[hash_index].next = n;
        }
        else{
            node* curr_node = hash_table[hash_index].next;
            while(curr_node->next != NULL){
                curr_node = curr_node->next;
            }
            node* n = new node(arr[i]);
            curr_node->next = n;
        }
    }
}
void HashTable::display(){
    for(int i=0; i<hash_size; i++){
        if(hash_table[i].next == NULL){
            cout<<0<<endl;
        }
        else{
            node* curr_node = hash_table[i].next;
            cout<<curr_node->key<<" ";
            while(curr_node->next != NULL){
                curr_node = curr_node->next;
                cout<<curr_node->key<<" ";
            }
            cout<<endl;
        }
    }
}
