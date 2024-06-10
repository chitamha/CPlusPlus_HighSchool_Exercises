#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>> n;
    long long A[n];
    for (int i=0; i<n; i++) cin>> A[i];
    for (int i=0; i<n; i++){
        if (i==0 && A[0]*A[1]<0){
            cout<< A[0]<< " ";
        }else if (i==n-1 && A[i-1]*A[i]<0){
            cout<< A[n-1]<< " ";
        }else if (A[i-1]*A[i]<0 || A[i]*A[i+1]<0){
            cout<< A[i]<< " ";
        }
    }
    return 0;
}
