#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll n, k, cnt=0;

int main(){
    cin>> n>> k;
    ll A[n+1];
    for (int i=1; i<=n; i++) cin>> A[i];
    A[0]=0;
    for (int i=1; i<=n; i++) A[i]+=A[i-1];
    for (int i=1; i<=n; i++){
        if (binary_search(A, A+i, A[i]-k))
            cnt++;
    }
    cout<< cnt;
    return 0;
}
