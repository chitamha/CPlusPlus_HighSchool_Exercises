#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, power;
vector<pair<ll, ll>> v;

int main(){
    freopen("DRAGON.INP", "r", stdin);
    freopen("DRAGON.OUT", "w", stdout);
    cin>> power>> n;
    v.resize(n);
    for (ll i=0; i<n; i++)
        cin>> v[i].first>> v[i].second;
    sort(v.begin(), v.end());
    ll i=0;
    for (i; i<n; i++){
        if (power>v[i].first) power+=v[i].second;
        else break;
    }
    if (i==n) cout<< "YES"<< endl;
    else{
        cout<< "NO"<< endl;
        cout<< n-i<< endl;
    }
    return 0;
}
