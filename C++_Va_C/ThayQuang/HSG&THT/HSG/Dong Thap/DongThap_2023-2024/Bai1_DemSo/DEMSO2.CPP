#include <bits/stdc++.h>
#define ll long long
using namespace std;

int m, n, q;

int dem(ll x){
    int tmp=0;
    for (int i=1; i<=min(m, n); i++){
        ll tmp2=x/i;
        if (tmp2*i==x && tmp2>=1 && tmp2<=1ll*max(m, n))
            tmp++;
    }
    return tmp;
}

int main(){
    freopen("DEMSO.INP", "r", stdin);
    freopen("DEMSO.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> m>> n>> q;
    ll x;
    while (q--) cin>> x, cout<< dem(x)<< "\n"; {}
    return 0;
}
