#include <iostream>
#include <string.h>
#include "graph.h"
#include <vector>
using namespace std;

void prims_MST(graph& g){
    vector<int> ver;
    vector<int> edges;
    int curr_Vertex = 0;

    while(ver.size() != g.v){
        if(!SearchVer(ver, curr_Vertex)){
            ver.push_back(curr_Vertex);
            InitializingEdges(edges,curr_Vertex, g.e*2, g.arr);
            // smallest edge find
            min_edge(g.arr, g.v, curr_Vertex, edges, ver);
            // save the remaining edges
            // change curr_Vertex value to selected edge
        }
    }
}

void min_edge(int** arr, int v, int& curr_Vertex, vector<int>& edges, vector<int>& ver){
    int r=0;
    int temp;
    int c=1;
    for(int i=0; i<edges.size(); i+=2){
        if(arr[edges[i]][edges[i+1]] < arr[r][c]){
            temp = SearchVer(ver, edges[i], edges[i+1]);
            if(temp != -1){
                r = i;
                c = i+1;
                curr_Vertex = temp;
            }
        }
        else if(i+2 >edges.size() && r==0){
            temp = SearchVer(ver, edges[i], edges[i+1]);
            if(temp != -1){
                curr_Vertex = temp;
            }
        }
    }
    edges.erase(edges[r]);

}

void InitializingEdges(vector<int>& edges, int curr_Vertex, int e, int** arr){
    for(int i=0; i<e; i++){
        if(i <e/2){
            edges.push_back(curr_Vertex);
            edges.push_back(i);
        }
        else{
            edges.push_back(i);
            edges.push_back(curr_Vertex);
        }
    }
}
bool SearchVer(vector<int>& arr, int curr_vertex){
    for(int i=0; i<arr.size(); i++){
        if(arr[i] == curr_vertex){
            return true;
        }
    }
    return false;
}
int SearchVer(vector<int>& arr, int ver1, int ver2){
    if(!SearchVer(arr,ver1) || !SearchVer(arr,ver2)){
        if(!SearchVer(arr,ver1)){
            return ver1;
        }
        else{
            return ver2;
        }
    }
    return -1;
}
