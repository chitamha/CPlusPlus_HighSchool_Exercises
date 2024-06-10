#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n, t;
ll ans;

bool check(ll mid, ll t, ll n, ll K[]){
    ll cnt=0;
    for (ll i=0; i<n; i++){
        cnt+=mid/K[i];
        if (cnt>=t) return true;
    }
    return false;
}

int main(){
    cin>> n>> t;
    ll K[n];
    for (ll i=0; i<n; i++) cin>> K[i];
    ll l=0, r=1e18; //t*(*min_element(K, K+n));
    while (l<=r){
        ll mid=(l+r)/2;
        if (check(mid, t, n, K)){
            ans=mid;
            r=mid-1;
        } else{
            l=mid+1;
        }
    }
    cout<< ans;
    return 0;
}
