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
