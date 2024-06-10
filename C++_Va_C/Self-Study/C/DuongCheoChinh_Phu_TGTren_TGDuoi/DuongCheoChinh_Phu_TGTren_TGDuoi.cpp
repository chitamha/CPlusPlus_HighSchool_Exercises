#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int n;
    cin>> n;
    int A[n][n];
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
        cin>> A[i][j];
        }
    }/*
    cout<< "Duong cheo chinh"<< endl;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (i==j){
                cout<< A[i][j]<< "  ";
            }
            else{
                cout<< "  ";
            }
        }
        cout<< endl;
    }
    cout<< "Duong cheo phu"<< endl;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (i==n-1-j){
                cout<< A[i][j]<< "  ";
            }
            else{
                cout<< "  ";
            }
        }
        cout<< endl;
    }
    cout<< "Tam gia duoi"<< endl;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (i>=j){
                cout<< A[i][j]<< " ";
            }
            else{
                cout<< " ";
            }
        }
        cout<< endl;
    }
    cout<< "Tam giac tren"<< endl;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (j>=i){
                cout<< A[i][j]<< " ";
            }
            else{
                cout<< "  ";
            }
        }
        cout<< endl;
    }*/
    cout<< "Tam giac duoi"<< endl;
    for (int i=0; i<n; i++){
        for (int j=0; j<=i; j++){
            cout<< A[i][j]<< " ";
        }
        cout<< endl;
    }
    cout<< "Tam giac tren"<< endl;
    for (int i=0; i<n; i++){
        for (int j=i; j<n; j++){
            cout<< A[i][j]<< " ";
        }
        cout<< endl;
    }
    cout<< "Duong cheo chinh"<< endl;
    for (int i=0; i<n; i++){
        cout<< A[i][i]<< "  ";
    }
    cout<< endl<< "Duong cheo phu"<< endl;
    for (int i=0; i<n; i++){
        cout<< A[i][n-1-i]<< "  ";
    }
}
