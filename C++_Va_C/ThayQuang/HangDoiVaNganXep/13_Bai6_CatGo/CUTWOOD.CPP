#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

ll n, ans=0;
priority_queue<ll, vector<ll>, greater<ll>> pq;

int main(){
    freopen("CUTWOOD.INP", "r", stdin);
    freopen("CUTWOOD.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll t; cin>> t;
    while (t--){
        cin>> n;
        for (ll i=1; i<=n; i++){
            ll x; cin>> x;
            pq.push(x);
        }
        while (pq.size()>1){
            ll tmp1=pq.top();
            pq.pop();
            ll tmp2=pq.top();
            pq.pop();
            pq.push(tmp1+tmp2);
            ans+=tmp1+tmp2;
        }
        cout<< ans<< endl;
        ans=0;
        pq.pop();
    }
    return 0;
}
