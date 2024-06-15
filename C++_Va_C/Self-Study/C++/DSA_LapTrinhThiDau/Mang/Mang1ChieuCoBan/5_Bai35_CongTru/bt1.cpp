#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>> n;
    int A[n], B[n-1];
    for (int i=0; i<n; i++) cin>> A[i];
    for (int i=0; i<n-1; i++) cin>> B[i];
    int kq=A[0];
    for (int i=0; i<n-1; i++){
        if (B[i]==1){
            kq+=A[i+1];
        } else if (B[i]==2){
            kq-=A[i+1];
        }
    }
    cout<< kq;
    return 0;
}
