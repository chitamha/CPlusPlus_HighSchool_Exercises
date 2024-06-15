#include <bits/stdc++.h>
#define maxn 1000006
#define ll long long
using namespace std;

ll n, x, sum=0, F[maxn];
vector<ll> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> x; v.resize(n+10);
    for (ll i=1; i<=n; i++) cin>> v[i], sum+=v[i];
    if (x>sum) return cout<< 0, 0;
    F[0]=1;
    for (ll i=1; i<=n; i++){
        for (ll j=x; j>=v[i]; j--){
            F[j]+=F[j-v[i]];
        }
    }
    cout<< F[x];
    return 0;
}
