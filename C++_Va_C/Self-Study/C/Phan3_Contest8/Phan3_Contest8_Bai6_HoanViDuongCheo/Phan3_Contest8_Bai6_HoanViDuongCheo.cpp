#include <iostream>
using namespace std;
int n;
int main(){
    cin>> n;
    int A[n][n];
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin>> A[i][j];
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout<< A[i][j]<< " ";
        }
        cout<< endl;
    }
    for (int i=0; i<n; i++){
        int tam=A[i][i];
        A[i][i]=A[i][n-1-i];
        A[i][n-1-i]=tam;
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout<< A[i][j]<< " ";
        }
        cout<< endl;
    }
}
