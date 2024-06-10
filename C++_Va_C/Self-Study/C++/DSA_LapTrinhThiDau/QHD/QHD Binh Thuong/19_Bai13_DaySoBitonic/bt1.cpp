#include <bits/stdc++.h>
#define maxn 10005
using namespace std;

int n;
int A[maxn], F1[maxn], F2[maxn];

// F1 tong cac phan tu tang dan
// F2 tong cac phan tu giam dan
// F3 tong Bitonic

int main(){
    cin>> n;
    for (int i=1; i<=n; i++) cin>> A[i];
    F1[1]=A[1];
    F2[n]=A[n];
    for (int i=1; i<=n; i++){
        F1[i]=A[i];
        for (int j=1; j<i; j++){
            if (A[i]>A[j]){
                F1[i]=max(F1[i], F1[j]+A[i]);
            }
        }
    }
    for (int i=n; i>=1; i--){
        F2[i]=A[i];
        for (int j=n; j>i; j--){
            if (A[i]>A[j]){
                F2[i]=max(F2[i], F2[j]+A[i]);
            }
        }
    }
    int Max=-1e9;
    for (int i=1; i<=n; i++){
        Max=max(Max, F1[i]+F2[i]-A[i]);
    }
    cout<< Max;
    return 0;
}
