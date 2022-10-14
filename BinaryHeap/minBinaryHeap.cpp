#include <iostream>
using namespace std;

class MinHeap{
    public:
    int* ptr;
    int index; 

    MinHeap(int size){
        if(size > 1){
            this->ptr = new int[size+1];
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
        index++;
    }
};

int main(){
    MinHeap h(5);
    h.InsertData(11);
    h.InsertData(3);
    h.InsertData(2);
    h.InsertData(1);
    h.InsertData(15);
    cout<<h.ptr[1]<<endl;
    cout<<h.ptr[2]<<endl;
    cout<<h.ptr[3]<<endl;
    cout<<h.ptr[4]<<endl;
    cout<<h.ptr[5]<<endl;

    return 0;
}
