#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, cnt=0, w;
vector<ll> v;

int main(){
    freopen("TILE.INP", "r", stdin);
    freopen("TILE.OUT", "w", stdout);
    cin>> n;
    v.resize(n);
    for (int i=0; i<n; i++) cin>> v[i];
    sort(v.begin(), v.end(), greater<ll>());
    w=v[0];
    cnt=1;
    while (w){
        w=min(w-1, v[cnt]);
        cnt++;
    }
    cout<< cnt;
    return 0;
}
