#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 100006
using namespace std;

ll n, k, pS[maxn], ans, id=1, cnt=1;
vector<ll> v;

bool check(ll ts){
    for (ll i=ts; i<=n; i++){
        if (ts*v[i]-(pS[i]-pS[i-ts])<=k){
            id=i;
            return 1;
        }
    }
    return 0;
}

int main(){
    //freopen("COUNT.INP", "r", stdin);
    //freopen("COUNT.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> k; v.resize(n+1, 0);
    for (ll i=1; i<=n; i++) cin>> v[i];
    sort(v.begin()+1, v.begin()+1+n);
    for (ll i=1; i<=n; i++) pS[i]=pS[i-1]+v[i];
    ll l=1, r=n;
    while (l<=r){
        ll mid=(l+r)/2;
        if (check(mid)){
            cnt=mid;
            ans=v[id];
            l=mid+1;
        } else r=mid-1;
    }
    cout<< cnt<< " "<< ans;
    return 0;
}
