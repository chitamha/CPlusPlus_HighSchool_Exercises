#include <bits/stdc++.h>
#define ll long long
#define llll pair<ll, ll>
#define fi first
#define se second
using namespace std;

ll n, m, ans=0;
vector<llll> v;

int main(){
    freopen("MILK.INP", "r", stdin);
    freopen("MILK.OUT", "w", stdout);
    cin>> n>> m;
    v.resize(m);
    for (int i=0; i<m; i++) cin>> v[i].fi>> v[i].se;
    sort(v.begin(), v.end());
    int i=0;
    while (n && i<m){
        ans+=v[i].fi*min(v[i].se, n);
        n-=min(v[i].se, n);
        i++;
    }
    cout<< ans;
    return 0;
}
