#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n;

int main(){
    //freopen("TUYENDO.INP", "r", stdin);
    //freopen("TUYENDO.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>> t;
    while (t--){
    cin>> n;
    vector<ll> v;
    for (int i=1; i<=n; i++){
        ll x; cin>> x;
        auto it=lower_bound(v.begin(), v.end(), x);
        if (it==v.end()) v.push_back(x);
        else (*it)=x;
    }
    cout<< n-v.size();
    cout<< endl;
    v.clear();
    }
    return 0;
}
