#include <iostream>
#include <math.h>
using namespace std;
bool ktNT(int n){
    if (n==1) return 0;
    for (int i=2; i<=sqrt(n); i++){
        if (n%i==0){
            return 0;
        }
    }
    return 1;
}
bool ktSoXh(int i, int A[]){
    for (int j=0; j<i; j++){
        if (A[i]==A[j]){
            return 0;
        }
    }
    return 1;
}
int n;
int main(){
    cin>> n;
    int A[n][n];
    int B[2*n];
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin>> A[i][j];
        }
    }
    int cnt=0;
    for (int i=0; i<n; i++){
        B[cnt]=A[i][i];
        ++cnt;
        B[cnt]=A[i][n-1-i];
        ++cnt;
    }
    for (int i=0; i<cnt; i++){
        cout<< B[i]<< " ";
    }
    cout<< endl;
    int dem=0;
    for (int i=0; i<cnt; i++){
        if (ktNT(B[i]) && ktSoXh(i, B)){
            ++dem;
            cout<< B[i]<< " ";
        }
    }
    cout<< endl<< dem;
}
