#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, q;
    cin>> n>> q;
    int A[n+5], F[n+5];
    for (int i=0; i<n; i++) cin>> A[i];
    memset(F, 0, sizeof F);
    while (q--){
        int l, r;
        cin>> l>> r;
        l--, r--;
        for (int i=l; i<=r; i++){
            F[i]++;
        }
    }
    sort(F, F+n);
    sort(A, A+n);
    int tong;
    for (int i=0; i<n; i++){
        tong+=F[i]*A[i];
    }
    cout<< tong;
    return 0;
}
