#include <iostream>
#include <math.h>
using namespace std;
int cow, col;
int A[1000][1000];
int B[1000];
int k=0;
bool Snt(int n){
    for (int i=2; i<=sqrt(n); i++){
        if (n%i==0){
            return false;
        }
    }
    return true;
}
void nhapMang(int a, int b, int A[][1000]){
    for (int i=0; i<cow; i++){
        for (int j=0; j<col; j++){
            cin>> A[i][j];
        }
    }
}
void xuatMang(int a, int b, int A[][1000]){
    for (int i=0; i<cow; i++){
        for (int j=0; j<col; j++){
            cout<< A[i][j]<< " ";
        }
        cout<< endl;
    }
}
void bdMang(int A[][1000], int B[]){
    for (int i=0; i<cow; i++){
        for (int j=0; j<col; j++){
            if (A[i][j]%2==0){
                B[k]=A[i][j];
                k++;
            }
        }
    }
}
int main(){
    freopen("NHAP.INP", "r", stdin);
    freopen("XUAT.OUT", "w", stdout);
    cin>> cow>> col;
    nhapMang(cow, col, A);
    cout<< "Xuat Mang"<< endl;
    xuatMang(cow, col, A);
    cout<< "Day so nguyen to la"<< endl;
    for (int i=0; i<cow; i++){
        for (int j=0; j<col; j++){
            if (Snt(A[i][j]) && A[i][j]!=1){
                cout<< A[i][j]<< " ";
            }
        }
    }
    bdMang(A, B);
     for (int i=0; i<=k-2; i++){
        for (int j=i+1; j<=k-1; j++){
            if (B[i]<B[j]){
                int tam;
                tam=B[i]; B[i]=B[j]; B[j]=tam;
            }
        }
    }
    cout<< endl<< "Day so chan la"<< endl;
    for (int i=0; i<k; i++){
        cout<< B[i]<< " ";
    }
}
