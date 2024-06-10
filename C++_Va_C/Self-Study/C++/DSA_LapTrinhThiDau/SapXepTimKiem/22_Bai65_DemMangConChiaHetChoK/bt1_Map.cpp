#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll n, cnt=0, tong=0;
map<ll, ll> mp;

int main(){
    cin>> n;
    for (ll i=0; i<n; i++){
        ll x, du;
        cin>> x;
        tong+=x;
        du=tong%n;
        if (du<0) du=tong-(tong/n-1)*n;
        //lam cho du > 0
        if (du==0) cnt++;
        if (mp.count(du)!=0) cnt+=mp[du];
        mp[du]++;
    }
    cout<< cnt;
    return 0;
}
