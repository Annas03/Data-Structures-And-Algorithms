#include <iostream>
#include <string>
#include <stack>
#include "node.h"
using namespace std;


void postfixEvaluation(string postfix){
    stack<int> s;
    for(int i = 0; i < postfix.length(); i++){
        if(int(postfix[i]) > 47){
            s.push(postfix[i] - '0');
        }
        else{
            int r = s.top();
            s.pop();
            int l = s.top();
            s.pop();
            switch (postfix[i]){
                case '+':
                    s.push(r+l);
                    break;
                case '-':
                    s.push(r-l);
                    break;
                case '*':
                    s.push(r*l);
                    break;
                case '/':
                    s.push(r/l);
                    break;
                case '^':
                    s.push(r^l);
                    break;
            }
        }
    }
    cout<<s.top();
}
void addingNode(node* p_ptr, node* curr_N){
    if(p_ptr->R_Node == NULL){
        p_ptr->R_Node = curr_N;
    }
    else{
        p_ptr->L_Node = curr_N;
    }
}
node* TreeExpression(node* p_ptr, string postfix){
    if(postfix.length() == 0){
        return p_ptr;
    }
    if(p_ptr == NULL){
        p_ptr = new node();
        p_ptr->num = postfix.back();
        postfix.pop_back();
        TreeExpression(p_ptr, postfix);
    }
    else{
        node* curr_N = new node();
        curr_N->num = postfix.back();
        addingNode(p_ptr, curr_N);
        if(int(postfix.back()) > 47){    // If it is a Num
            postfix.pop_back();
            TreeExpression(p_ptr, postfix);
        }
        else{  //If not A Num
            postfix.pop_back();
            TreeExpression(curr_N, postfix);
        }
    }
    return p_ptr;
}

int main(){
    string postfix;
    // cout<<"Postfix:";
    // cin>>postfix;
    postfix = "12-";
    // postfixEvaluation(postfix);

    node* root = NULL;
    node* res = TreeExpression(root, postfix);
    cout<<res->num<<endl;
    return 0;
}
