#include <bits/stdc++.h>
using namespace std;

int n, q;

int main(){
    cin>> n>> q;
    int A[n+5];
    int F[n+5];
    memset(F, 0, sizeof F);
    for (int i=0; i<n; i++) cin>> A[i];
    while (q--){
        int l, r;
        cin>> l>> r;
        l--, r--;
        F[l]+=1;
        F[r+1]-=1;
    }
    int preSF[n+5];
    preSF[0]=F[0];
    for (int i=1; i<n; i++){
        preSF[i]=preSF[i-1]+F[i];
    }
    sort(preSF, preSF+n, greater<int>());
    sort(A, A+n, greater<int>());
    int tong=0;
    for (int i=0; i<n; i++){
        tong+=preSF[i]*A[i];
    }
    cout<< tong;
    return 0;
}
