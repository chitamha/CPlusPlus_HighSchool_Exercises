#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, m, ans=-1, ma=0;
vector<ll> v;

bool check(ll h){
    ll total=0;
    for (ll i=1; i<=n; i++){
        total+=max(0ll, v[i]-h);
        if (total>=m) return true;
    }
    return false;
}

int main(){
    freopen("WOOD.INP", "r", stdin);
    freopen("WOOD.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m; v.resize(n+1);
    for (ll i=1; i<=n; i++){
        cin>> v[i];
        ma=max(ma, v[i]);
    }
    ll left=0, right=ma;
    while (left<=right){
        ll mid=(left+right)/2;
        if (check(mid)){
            ans=mid;
            left=mid+1;
        } else right=mid-1;
    }
    cout<< ans;
    return 0;
}
