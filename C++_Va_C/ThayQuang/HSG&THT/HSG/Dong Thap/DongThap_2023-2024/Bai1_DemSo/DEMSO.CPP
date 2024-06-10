#include <bits/stdc++.h>
#define ll long long
using namespace std;

int m, n, q;
vector<int> Cnt;

int dem(ll x){
    int tmp=0;
    for (int i=1; i<=min(m, n); i++){
        ll tmp2=x/i;
        if (tmp2*i==x && tmp2>=1 && tmp2<=1ll*max(m, n))
            tmp++;
    }
    return tmp;
}

void sub12(){
    for (int i=1; i<=m; i++){
        for (int j=1; j<=n; j++) Cnt[i*j]++;
    }
}

int main(){
    freopen("DEMSO.INP", "r", stdin);
    freopen("DEMSO.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> m>> n>> q;
    ll x;
    if (m<=1000 && n<=1000){
        Cnt.resize(m*n+10, 0);
        sub12();
        while (q--) cin>> x, cout<< Cnt[x]<< "\n"; {}
    } else while (q--) cin>> x, cout<< dem(x)<< "\n"; {}
    return 0;
}
