#include <iostream>
using namespace std;

class node{
    public:
        char num;
        node* L_Node;
        node* R_Node;

        node(){
            L_Node = NULL;
            R_Node = NULL;
        }
};
