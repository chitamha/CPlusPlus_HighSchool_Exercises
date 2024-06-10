#include <iostream>
using namespace std;
int A[1000], B[1000], C[1000];
int m, n;
void nhapA(int m, int A[]){
    for (int i=0; i<m; i++){
        cin>> A[i];
    }
}
void sapXep(int m, int A[]){
    for (int i=0; i<=m-2; i++){
        for (int j=i+1; j<=m-1; j++){
            if (A[i]>A[j]){
                int tam;
                tam=A[i]; A[i]=A[j]; A[j]=tam;
            }
        }
    }
    for (int i=0; i<m; i++){
        cout<< A[i]<< " ";
    }
}
int main(){
    cin>> m>> n;
    nhapA(m, A);
    for (int j=0; j<n; j++){
        cin>> B[j];
        for (int i=0; i<m; i++){
            if (B[j]==A[i]){
                cout<< "Da trung gia tri, moi nhap lai"<< endl;
            j=-1;
            break;
            }
        }
    }
    cout<< endl<< "Sap xep A"<< endl;
    sapXep(m, A);
    cout<< endl<< "Sap xep B"<< endl;
    sapXep(n, B);
    cout<< endl;
    int k=0;
    for (int i=m; i<m+n; i++){
        A[i]=B[k];
        k++;
    }
    cout<< "Sap xep noi 2 mang"<< endl;
    int kkk=m+n;
    sapXep(kkk, A);
}
