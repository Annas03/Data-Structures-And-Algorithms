#include <iostream>
using namespace std;

class MinHeap{
    public:
    int size;
    int* ptr;
    int index; 

    MinHeap(int size){
        if(size > 1){
            this->size = size+1;
            this->ptr = new int[size];
            index = 1;
        }
        else{
            cout<<"Invalid size"<<endl;
        }
    }
    void InsertData(int val){
        int temp;
        int curr_Index = index;
        if(ptr[index/2] < val || index == 1){
            ptr[index] = val;
        }
        else{
            while(ptr[index/2] > val || index > 1){
                if(index/2 == 1){
                    ptr[index] = ptr[index/2];
                    ptr[index/2] = val;
                    break;
                }
                ptr[index] = ptr[index/2];
                index = index/2;
            }
            index = curr_Index;
        }
        if(index < size-1){
            index++;
        }
    }
    void DeleteData(){
        int curr_index = index;
        index = 1;
        if(curr_index == 1 && ptr[curr_index] != 0){
            ptr[curr_index] = 0;
            return;
        }
        else if(curr_index == 1 && ptr[curr_index] == 0){
            cout<<"Queue is Empty"<<endl;
            return;
        }
        while(index <= curr_index){
            if(index*2 > curr_index){
                ptr[index] = ptr[curr_index];
                ptr[curr_index] = 0;
                break;
            }
            else if(ptr[2*index] < ptr[2*index+1] || (index*2 + 1 > curr_index)){
                ptr[index] = ptr[2*index];
                ptr[2*index] = 0;
                index = 2*index;
            }
            else if(ptr[2*index] > ptr[2*index+1]){
                ptr[index] = ptr[2*index+1];
                ptr[2*index+1] = 0;
                index = 2*index+1;
            }
        }
        index = curr_index - 1;
    }
    void display(){
        int i = 1;
        while(i < size){
            if(i <= index){
                cout<<ptr[i]<<" ";
            }
            else{
                cout<<"-"<<" ";
            }
            i+=1;
        }
    }
};

int main(){
    MinHeap h(5);
    h.InsertData(11);
    cout<<h.index;
    h.InsertData(3);
    h.InsertData(2);
    h.InsertData(1);
    h.InsertData(15);
    h.DeleteData();
    h.DeleteData();
    h.DeleteData();
    h.DeleteData();
    h.DeleteData();
    h.InsertData(1);
    cout<<h.index;
    h.display();

    return 0;
}
