#include <iostream>
#include <string.h>
using namespace std;

void prims_MST(graph& g){
    int ver[g.v];
    int curr_Vertex = 0;

    while(verNotFull(ver,g.v)){
        if(!SearchVer(ver, curr_Vertex, g.v)){
            InsertVer(ver, curr_Vertex,g.v);
        }
    }
}



void InsertVer(int* arr, int curr_Vertex, int v){
    for(int i=0;i<v;i++){
        if(arr[i]==0){
            arr[i] == curr_Vertex+1;
            break;
        }
    }
}
bool verNotFull(int* arr,int v){
    for(int i=0; i<v; i++){
        if(arr[i] == 0){
            return true;
        }
    }
    return false;
}
bool SearchVer(int* arr, int curr_vertex, int v){
    for(int i=0; i<v; i++){
        if(arr[i] == curr_vertex+1){
            return true;
        }
    }
    return false;
}