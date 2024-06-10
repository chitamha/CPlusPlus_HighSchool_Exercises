#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll n, k, cnt=0, tong=0;
map<ll, ll> mp;

int main(){
    cin>> n>> k;
    for (ll i=0; i<n; i++){
        ll x; cin>> x;
        tong+=x;
        if (tong==k) cnt++;
        if (mp.count(tong-k)) cnt+=mp[tong-k];
        //mp[tong-k] chac chan = 1
        mp[tong]++;
    }
    cout<< cnt;
    return 0;
}
