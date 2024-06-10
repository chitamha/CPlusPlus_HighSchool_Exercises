#include <iostream>
using namespace std;
int A[1000][1000];
int B[1000][1000];
int cow, col;
int main(){
    freopen("CHUYENVI.INP", "r", stdin);
    freopen("CHUYENVI.OUT", "w", stdout);
    cin>> cow>> col;
    for (int i=0; i<cow; i++){
        for (int j=0; j<col; j++){
            cin>> A[i][j];
        }
    }
    /*
    cout<< "Xuat mang"<< endl;
    for (int i=0; i<cow; i++){
        for (int j=0; j<col; j++){
            cout<< A[i][j]<< " ";
        }
        cout<< endl;
    }
    *//*
    for (int j=0; j<col; j++){
        for (int i=0; i<cow; i++){
            cout<< A[i][j]<< " ";
        }
        cout<< endl;
    }*/
    for (int i=0; i<col; i++){
        for (int j=0; j<cow; j++){
            cout<< A[j][i]<< " ";
        }
        cout<< endl;
    }



















}
