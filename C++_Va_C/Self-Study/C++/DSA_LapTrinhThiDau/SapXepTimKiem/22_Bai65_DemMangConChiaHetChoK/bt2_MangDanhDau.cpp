#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll n, cnt=0, tong=0;

int main(){
    cin>> n;
    ll DanhDau[n];
    memset(DanhDau, 0, sizeof DanhDau);
    for (ll i=0; i<n; i++){
        ll x, du;
        cin>> x;
        tong+=x;
        du=tong%n;
        if (du<0) du=tong-(tong/n-1)*n;
        //lam cho du > 0
        if (du==0) cnt++;
        if (DanhDau[du]!=0) cnt+=DanhDau[du];
        DanhDau[du]++;
    }
    cout<< cnt;
    return 0;
}
