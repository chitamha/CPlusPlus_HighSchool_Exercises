#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll n, k, ans=-1, A[50006];

bool check (ll mid){
    ll l=1, r=1, sum=0;
    for (r; r<=mid; r++) sum+=A[r];
    if (sum>=k) return true;
    for (l; l<=n-mid+1; l++){
        sum+=A[r]; r++;
        sum-=A[l];
        if (sum>=k) return true;
    }
    return false;
}

int main(){
    freopen("LUYENTAP.INP", "r", stdin);
    freopen("LUYENTAP.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> k;
    for (int i=1; i<=n; i++) cin>> A[i];
    ll l=1, r=n;
    while (l<=r){
        ll mid=(l+r)/2;
        if (check(mid)){
            ans=mid;
            r=mid-1;
        } else l=mid+1;
    }
    cout<< ans;
    return 0;
}
