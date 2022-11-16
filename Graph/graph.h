#include<iostream>
#include <fstream>
#include <string.h>
#include <vector>
using namespace std;

class graph{
    public:
    int v,e;
    int** arr;
    graph(string filename);
    void display();
    void InitializeMatrix();
    void prims_MST();
    void min_edge(int& curr_Vertex, vector<int>& rem_edges, vector<int>& ver, vector<int>& edges);
    void Modifyrem_edges(vector<int>& rem_edges, vector<int>& edges);
    void InitializingEdges(vector<int>& rem_edges, int curr_Vertex, int e);
    bool SearchVer(vector<int>& arr, int curr_vertex);
    int new_Ver(vector<int>& arr, int ver1, int ver2);
    bool SearchEdge(int ver1, int ver2, vector<int>& rem_edge);
    ~graph();
};

graph::graph(string filename){
    bool neg_vrt = false;
    bool inv_inp = false;
    bool isWeighted;
    string myText;
    string r,c;
    ifstream MyReadFile(filename);
    int i = 0;
    while (getline (MyReadFile, myText)) {
        if(myText == ""){
            inv_inp = true;
        }
        if(i == 0){
            if(stoi(myText) < 0){
                inv_inp = true;
                break;
            }
            v = stoi(myText);
            InitializeMatrix();
        }
        else if(i == 1){
            if(stoi(myText) < 0){
                inv_inp = true;
                break;
            }
            e = stoi(myText);
        }
        else if(i >= 2 && i < 2+e){
            int ind = 0;
            string t_var;
            for(int j=0; j <= myText.length(); j++){
                if(myText[j] == ','){
                    if(ind == 0){r = myText.substr(ind,j-ind);}
                    else{c =myText.substr(ind,j-ind);isWeighted = true;}
                    ind = j+1;
                }
                else if(j == myText.length()){
                    if(isWeighted){
                        if(j != ind){t_var = myText.substr(ind, j-ind);}
                        else{t_var = myText.back();}
                        continue;
                    }
                    else{  
                        if(j != ind){c = myText.substr(ind, j-ind);}
                        else{c = myText.back();};
                    }
                }
                else if(myText[j] == '-'){
                    neg_vrt = true;
                    break;
                }
            }
            if(neg_vrt){
                inv_inp = true;
                break;
            }
            if(isWeighted){arr[stoi(r)][stoi(c)] = stoi(t_var);}
            else{arr[stoi(r)][stoi(c)] = 1;}
        }
        i++;
    }
    if((i-1) > 1+e || (i-1) < 1+e){
        inv_inp = true;
    }
    if(inv_inp){
        cout<<"Invalid Input"<<endl;
    }
    MyReadFile.close();
}
void graph::display(){
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
void graph::InitializeMatrix(){
    arr = new int*[v];
    for(int i=0; i<v; i++){
        arr[i] = new int[v];
    }

    for(int i = 0; i<v; i++){
        for(int j=0; j<v; j++){
            arr[i][j] = 0;
        }
    }
}
void graph::prims_MST(){
    vector<int> ver;
    vector<int> edges;
    vector<int> rem_edges;
    int curr_Vertex = 0;
    ver.push_back(curr_Vertex);
    while(ver.size() != v){
        InitializingEdges(rem_edges,curr_Vertex, e*2);
        for(int j=0; j<rem_edges.size(); j++){
            cout<<rem_edges[j];
        }
        cout<<endl;
        Modifyrem_edges(rem_edges,edges);
        for(int k=0; k<edges.size(); k++){
            cout<<edges[k];
        }
        cout<<endl;
        min_edge(curr_Vertex, rem_edges, ver,edges);
        ver.push_back(curr_Vertex);
    }
    // Setting values of all coordinates present in rem_edges to 0.
    for(int i=0; i<rem_edges.size()/2; i+=2){
        arr[rem_edges[i]][rem_edges[i+1]] = 0;
    }
}
void graph::min_edge(int& curr_Vertex, vector<int>& rem_edges, vector<int>& ver, vector<int>& edges){
    int r=0;
    int c=r+1;
    int temp;
    for(int j=0; j<rem_edges.size(); j+=2){
        if(arr[rem_edges[j]][rem_edges[j+1]] < arr[rem_edges[r]][rem_edges[c]]){
            temp = new_Ver(ver, rem_edges[j], rem_edges[j+1]);
            if(temp != -1){
                r = j;
                curr_Vertex = temp;
            }
            else{
                rem_edges.erase(rem_edges.begin()+j, rem_edges.begin()+1+j);
                j-=2;
            }
        }
        else if(j+2 >=rem_edges.size() && r==0){
            temp = new_Ver(ver, rem_edges[r], rem_edges[c]);
            if(temp != -1){
                curr_Vertex = temp;
            }
            else{
                rem_edges.erase(rem_edges.begin()+r, rem_edges.begin()+ c);
                j-=2;
            }
        }
    }
    edges.push_back(rem_edges[r]);
    edges.push_back(rem_edges[c]);
}
bool graph::SearchEdge(int ver1, int ver2, vector<int>& rem_edge){
    for(int i=0; i<rem_edge.size()/2; i+=2){
        if(rem_edge[i] == ver1 && rem_edge[i+1] == ver2){
            return true;
        }
    }
    return false;
}
void graph::Modifyrem_edges(vector<int>& rem_edges, vector<int>& edges){
    for(int i=0; i<rem_edges.size(); i+=2){
        for(int j=0; j<edges.size(); j+=2){
            if(rem_edges[i] == edges[j] && rem_edges[i+1] == edges[j+1]){
                rem_edges.erase(rem_edges.begin()+i, rem_edges.begin()+1+i);
            }
        }
    }
}
void graph::InitializingEdges(vector<int>& rem_edges, int curr_Vertex, int e){
    for(int i=0; i<e; i++){
        if(i <e/2 && arr[curr_Vertex][i] != 0 && !SearchEdge(curr_Vertex,i, rem_edges)){
            rem_edges.push_back(curr_Vertex);
            rem_edges.push_back(i);
        }
        else if(i >= e/2 && arr[i-e/2][curr_Vertex] != 0 && !SearchEdge(i-e/2,curr_Vertex, rem_edges)){
            rem_edges.push_back(i);
            rem_edges.push_back(curr_Vertex);
        }
    }
}
int graph::new_Ver(vector<int>& arr, int ver1, int ver2){
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
bool graph::SearchVer(vector<int>& arr, int curr_vertex){
    for(int i=0; i<arr.size(); i++){
        if(arr[i] == curr_vertex){
            return true;
        }
    }
    return false;
}



graph::~graph(){
    for(int i=0; i<v; i++){
        delete[] arr[i];
    }
    delete[] arr;
}
