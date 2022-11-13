#include<iostream>
#include"HashTable.h"
using namespace std;

int main(){
    int arr[] = {100, 44, 5,2, 13, 33,15,66,99,88};
    HashTable h;
    h.Insert(arr, 10);
    h.display();
    return 0;
}