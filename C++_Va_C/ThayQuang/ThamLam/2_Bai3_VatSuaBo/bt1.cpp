#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, sua, cnt=0;
vector<ll> v;

int main(){
    freopen("MILK2.INP", "r", stdin);
    freopen("MILK2.OUT", "w", stdout);
    cin>> n;
    v.resize(n);
    for (ll i=0; i<n; i++) cin>> v[i];
    sort(v.begin(), v.end(), greater<ll>());
    for (ll i=0; i<n; i++){
        sua+=max(v[i]-cnt, 1ll*0);
        cnt++;
    }
    cout<< sua<< endl;
    return 0;
}
