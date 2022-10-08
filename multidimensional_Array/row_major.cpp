#include<iostream>
using namespace std;

int main(){
    char des;
    int n;

    cout<<"Enter number of dimensions: ";
    cin>>n;

    int s[n];
    int I[n];
    int total = 1;

    for(int i=0; i<n; i++){
        cout<<"S["<<i<<"]: ";
        cin>>s[i];
        total*=s[i];
    }
    int arr[total];
    int* BA = &arr[0];
    int len = sizeof(arr)/sizeof(int);

    //loop for assigning values of array elements
    for(int i=0; i < len; i++){ 
        arr[i] = i+1;
    }

    // loop for displaying values of array
    for(int i=0; i < len; i++){
        cout<<arr[i]<<" "<<&arr[i]<<endl;
    }

    while(true){ 
        int res = 0;
        for(int i=0; i < n; i++){
            cout<<"I["<<i<<"]: ";
            cin>>I[i];
        }
        for(int i=0; i < n; i++){
            int t = 1;
            for(int j=i+1; j < n; j++){
                t *= s[j];
            }
            res+=t*I[i];
        }

        cout<<*(BA + res)<<" "<<BA + res<<endl;
        cout<<"Continue(Y,N):";
        cin>>des;
        if(des == 'N'){
            break;
        }
    }

    return 0;
}