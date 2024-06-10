#include <iostream>
using namespace std;
int A[500][500];
int B[500][500];
int C[500][500];
int n, m, q;
int main(){
    freopen("NHANMATRAN.INP", "r", stdin);
    freopen("NHANMATRAN.OUT", "w", stdout);
    cin>> n>> m>> q;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin>> A[i][j];
        }
    }
    for (int i=0; i<m; i++){
        for (int j=0; j<q; j++){
            cin>> B[i][j];
        }
    }/*
    cout<< "Xuat mang"<< endl;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout<< A[i][j]<< " ";
        }
        cout<< endl;
    }
    for (int i=0; i<m; i++){
        for (int j=0; j<q; j++){
            cout<< B[i][j]<< " ";
        }
        cout<< endl;
    }*/
    for (int i=0; i<n; i++){
        for (int j=0; j<q; j++){
            C[i][j]=0;
            for (int k=0; k<m; k++){
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<q; j++){
            cout<< C[i][j]<< " ";
        }
        cout<< endl;
    }
}
