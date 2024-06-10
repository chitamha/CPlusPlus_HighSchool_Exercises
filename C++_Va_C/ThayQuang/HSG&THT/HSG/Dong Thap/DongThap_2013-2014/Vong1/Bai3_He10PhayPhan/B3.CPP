#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n;

ll tongchuso(ll k){
    ll sum=0;
    while (k){
        sum+=k%10;
        k/=10;
    }
    return sum;
}

ll solution(ll nu){
    for (ll i=1; 1ll*i*i<=nu; i++){
        if (i*(i+tongchuso(i))==nu) return i;
    }
    return -1;
}

ll solution2(ll n){
    ll t=sqrt(n);
    for (ll i=-81; i<=81; i++){
        ll nu=i+t;
        if (nu*(nu+tongchuso(nu))==n)
            return nu;
    }
    return -1;
}

int main(){
    freopen("COSO.INP", "r", stdin);
    freopen("COSO.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    cout<< solution2(n);
    return 0;
}
