#include <iostream>
using namespace std;
int main(){
    int n;
    cin>> n;
    int A[n];
    for (int i=0; i<n; i++){
        cin>> A[i];
    }
    for (int i=0; i<n-1; i++){
        for (int j=i+1; j<n; j++){
            if (A[i]>A[j]){
                int tam=A[i];
                A[i]=A[j];
                A[j]=tam;
            }
        }
    }
    for (int i=0; i<n; i++){
        cout<< A[i]<< " ";
    }
    cout<< endl;
    bool check;
    cout<< A[0]<< " ";
    for (int i=1; i<n; i++){
        check=false;
        for (int j=0; j<i; j++){
            if (A[i]==A[j]){
                check=true;
                break;
            }
        }
        if (!check){
            cout<< A[i]<< " ";
        }
    }
}
