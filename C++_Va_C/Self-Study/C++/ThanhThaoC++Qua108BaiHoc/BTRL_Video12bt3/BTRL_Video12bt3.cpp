#include <iostream>
using namespace std;
int A[500][500];
int B[500][500];
int C[500][500];
int m, k, n;
int main(){
    freopen("NHANMATRAN.INP", "r", stdin);
    freopen("NHANMATRAN.OUT", "w", stdout);
    cin>> m>> k;
    for (int i=0; i<m; i++){
        for (int j=0; j<k; j++){
            cin>> A[i][j];
        }
    }
    cin>> n;
    for (int i=0; i<k; i++){
        for (int j=0; j<n; j++){
            cin>> B[i][j];
        }
    }
    cout<< "Xuat mang"<< endl;
    cout<< "Mang A"<< endl;
    for (int i=0; i<m; i++){
        for (int j=0; j<k; j++){
            cout<< A[i][j]<< " ";
        }
        cout<< endl;
    }
    cout<< "Mang B"<< endl;
    for (int i=0; i<k; i++){
        for (int j=0; j<n; j++){
            cout<< B[i][j]<< " ";
        }
        cout<< endl;
    }
    cout<< "Mang C"<< endl;
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            for (int h=0; h<k; h++){
                C[i][j]=A[i][h]*B[h][j];
            }
        }
    }
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            cout<< C[i][j]<< " ";
        }
        cout<< endl;
    }
}

