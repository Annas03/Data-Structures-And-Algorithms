#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class Graph{
    public:
    int v,e;
    int** arr;
    Graph(string filename){
        bool neg_vrt = false;
        string myText;
        string r,c;
        int ind;
        ifstream MyReadFile(filename);
        int i = 0;
        while (getline (MyReadFile, myText)) {
            if(myText == ""){
                cout<<"Invalid Input"<<endl;
            }
            if(i == 0){
                if(stoi(myText) < 0){
                    cout<<"Invalid Input"<<endl;
                    break;
                }
                v = stoi(myText);
                InitializeMatrix();
            }
            else if(i == 1){
                if(stoi(myText) < 0){
                    cout<<"Invalid Input";
                    break;
                }
                e = stoi(myText);
            }
            else if(i >= 2 && i < 2+e){
                for(int j=0; j < myText.length(); j++){
                    if(myText[j] == ','){
                        r = myText.substr(0,j);
                        ind = j+1;
                    }
                    else if(j == myText.length()-1){
                        if(j != ind){c = myText.substr(ind, j-ind);}
                        else{c = myText.back();};
                    }
                    else if(myText[j] == '-'){
                        neg_vrt = true;
                        break;
                    }
                }
                if(neg_vrt){
                    cout<<"Invalid Input"<<endl;
                    break;
                }
                arr[stoi(r)][stoi(c)] = 1;
            }
            i++;
        }
        MyReadFile.close();
    }
    void display(){
        for(int i=0; i<v; i++){
            for(int j=0; j<v; j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    void InitializeMatrix(){
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
    ~Graph(){
        for(int i=0; i<v; i++){
            delete[] arr[i];
        }
        delete[] arr;
    }

};

int main(){
    Graph g("sample.txt");
    g.display();
    return 0;
}