#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, c, ans=1;

int main(){
    cin>> n>> c;
    ll A[n+1];
    for (ll i=1; i<=n; i++) cin>> A[i];
    for (ll i=2; i<=n; i++){
        if (A[i]-A[i-1]<=c) ans++;
        else ans=1;
    }
    cout<< ans;
    return 0;
}
