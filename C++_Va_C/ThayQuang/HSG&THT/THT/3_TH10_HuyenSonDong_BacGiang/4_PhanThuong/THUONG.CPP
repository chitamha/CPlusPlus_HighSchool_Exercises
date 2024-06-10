#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n; ll ans=0;
int Dem[250];

ll c2n(int n){
    return 1ll*n*(n-1)/2;
}

int main(){
    freopen("THUONG.INP", "r", stdin);
    freopen("THUONG.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    for (int i=1; i<=n; i++){
        ll x; cin>> x;
        x=x+2000000000;
        Dem[x%200]++;
    }
    for (int i=0; i<200; i++) ans+=c2n(Dem[i]);
    cout<< ans;
    return 0;
}
