#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 1000006
using namespace std;

ll n, A[maxn], B[maxn];
vector<pair<ll, ll>> Loi, Lo;

bool loi(pair<ll, ll> a, pair<ll, ll> b){
    if (a.fi==b.fi) return a.se>b.se;
    else return a.fi<b.se;
}

bool lo(pair<ll, ll> a, pair<ll, ll> b){
    if (a.se==b.se) return a.fi<b.fi;
    else return a.se>b.se;
}

bool check(ll x){
    for (auto it:Loi){
        x=x-it.fi;
        if (x<0) return 0;
        x=x+it.se;
    }
    for (auto it:Lo){
        x=x-it.fi;
        if (x<0) return 0;
        x=x+it.se;
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    for (ll i=1; i<=n; i++) cin>> A[i];
    for (ll i=1; i<=n; i++) cin>> B[i];
    for (ll i=1; i<=n; i++){
        if (B[i]>=A[i]) Loi.push_back({A[i], B[i]});
        else Lo.push_back({A[i], B[i]});
    }
    sort(Loi.begin(), Loi.end(), loi);
    sort(Lo.begin(), Lo.end(), lo);
    ll l=0, r=1e18, mid;
    while (l<=r){
        mid=(l+r)/2;
        if (check(mid)) r=mid-1;
        else l=mid+1;
    }
    cout<< r+1;
    return 0;
}
