#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 1000005
using namespace std;

ll n, k, F[1005][1005], MOD=1000000007;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll t; cin>> t;
    for (ll i=1; i<=1000; i++){
        F[i][i]=1;
        F[i][1]=i;
    }
    for (ll i=3; i<=1000; i++){
        for (ll j=2; j<i; j++){
            F[i][j]=(F[i-1][j]+F[i-1][j-1])%MOD;
        }
    }
    while (t--){
        cin>> n>> k;
        cout<< F[n][k]<< "\n";
    }
    return 0;
}
