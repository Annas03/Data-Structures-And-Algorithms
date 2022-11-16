#include <iostream>
#include <string.h>
#include "graph.h"
#include <vector>
using namespace std;

void prims_MST(graph& g){
    vector<int> ver;
    vector<int> edges;
    vector<int> rem_edges;
    int curr_Vertex = 0;

    while(ver.size() != g.v){
        if(!SearchVer(ver, curr_Vertex)){
            ver.push_back(curr_Vertex);
            InitializingEdges(rem_edges,curr_Vertex, g.e*2, g.arr);
            Modifyrem_edges(rem_edges,edges);
            min_edge(g.arr, curr_Vertex, rem_edges, ver);
            // edges.erase(edges.begin() + min_edge(g.arr, g.v, curr_Vertex, edges, ver), edges.begin() + min_edge(g.arr, g.v, curr_Vertex, edges, ver) + 1);
        } 
    }
}

void min_edge(int** arr,int& curr_Vertex, vector<int>& rem_edges, vector<int>& ver){
    // find minimum edges coordinates
    // Update curr_Vertex
    int r=0;
    int temp;
    int c=1;
    for(int i=0; i<rem_edges.size(); i+=2){
        if(arr[rem_edges[i]][rem_edges[i+1]] < arr[r][c]){
            temp = SearchVer(ver, rem_edges[i], rem_edges[i+1]);
            if(temp != -1){
                r = i;
                c = i+1;
                curr_Vertex = temp;
            }
        }
        else if(i+2 >rem_edges.size() && r==0){
            temp = SearchVer(ver, rem_edges[i], rem_edges[i+1]);
            if(temp != -1){
                curr_Vertex = temp;
            }
        }
    }
}

void modifyrem_edges(vector<int>& rem_edges, vector<int>& edges){
    for(int i=0; i<rem_edges.size()/2; i+=2){
        for(int j=0; j<edges.size()/2; j+=2){
            if()
        }
    }
}

void InitializingEdges(vector<int>& rem_edges, int curr_Vertex, int e, int** arr){
    for(int i=0; i<e; i+=2){
        if(i <e/2){
            rem_edges.push_back(curr_Vertex);
            rem_edges.push_back(i);
        }
        else{
            rem_edges.push_back(i);
            rem_edges.push_back(curr_Vertex);
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
