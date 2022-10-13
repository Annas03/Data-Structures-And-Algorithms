#include <iostream>
using namespace std;

class stack{
    public:
    int top = 0;
    int *ptr;
    stack(){
        this->ptr = NULL;
    }

    void push(int val){
        if(this->top == 0){
            this->ptr = new int[this->top+1];
            this->ptr[0] = val;
            top++;
            return;
        }
        int temp_arr[top];

        // copying values to temp array
        for(int i=0; i<top; i++){
            temp_arr[i] = this->ptr[i];
        }
        delete[] ptr;

        this->top += 1;
        this->ptr = new int[top];

        //assigning values to new array
        for(int i=0; i<top-1; i++){
            this->ptr[i] = temp_arr[i];
        }
        this->ptr[top-1] = val;
        // ptr = newArr(ptr, top, val);

    }
    int pop(){

        if(top == 0){
            cout<<"Stack is empty"<<endl;
            return;
        }
        int temp_arr[top-1];
        int temp;

        // copying values to temp array
        for(int i=0; i<top-1; i++){
            temp_arr[i] = this->ptr[i];
        }
        temp = ptr[top-1];
        delete[] ptr;

        this->top -= 1;
        this->ptr = new int[top];

        //assigning values to new array
        for(int i=0; i<top; i++){
            this->ptr[i] = temp_arr[i];
        }
        return temp;
    }
    void display(){
        for(int i = 0; i < this->top; i++){
            cout<<this->ptr[i]<<endl;
        }
    }
    ~stack(){
        delete ptr;
    }

};

int main(){
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    s.display();
    cout<<s.top;


    return 0;
}
