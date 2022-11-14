#include<iostream>
using namespace std;

class HashTable{
    public:
    int hash_size, hash_index;
    float load_factor;
    int* hash_table;
    HashTable();
    void Insert(int* arr, int lenght);
    int filledCells();
    void display();
    void IncreasingHashTable();
};

HashTable::HashTable(){
    load_factor = 0;
    hash_size = 10;
    hash_table = new int[hash_size];

    for(int i=0; i<hash_size; i++){
        hash_table[i] = -1;
    }
}
void HashTable::Insert(int* arr, int lenght){
    for(int i=0; i<lenght; i++){
        if(load_factor <= 0.5){
            hash_index = arr[i]%hash_size;
            if(hash_table[hash_index] != -1){
                int j = hash_index;
                while(hash_table[j] != -1){
                    j = (j+1)%hash_size;
                }
                hash_table[j] = arr[i];
            }
            else{
                hash_table[hash_index] = arr[i];
            }
        }
        else{
            hash_size*=2;
            IncreasingHashTable();
            i--;
        }
        load_factor = static_cast<float>(filledCells())/static_cast<float>(hash_size);
        // cout<<load_factor<<endl;
    }
}
int HashTable::filledCells(){
    int count=0;
    for(int i=0; i<hash_size; i++){
        if(hash_table[i] != -1){
            count++;
        }
    }
    return count;
}
void HashTable::display(){
    for(int i=0; i<hash_size; i++){
        cout<<hash_table[i]<<" ";
    }
    cout<<endl;
}
void HashTable::IncreasingHashTable(){
    int temp_arr[hash_size/2];
    for(int i=0; i<hash_size/2; i++){
        temp_arr[i] = hash_table[i];
    }
    delete[] hash_table;
    hash_table = new int[hash_size];
      for(int i=0; i<hash_size; i++){
        if(i<hash_size/2){
            hash_table[i] = temp_arr[i];
        }
        else{hash_table[i] = -1;}
    }
}
