#include<iostream>
#include"HashTable.h"
using namespace std;


int main(){
    int arr[] = {5,7,19,9,29,11,13};
    HashTable h;
    h.Insert(arr, 7);
    h.display();
    return 0;
}