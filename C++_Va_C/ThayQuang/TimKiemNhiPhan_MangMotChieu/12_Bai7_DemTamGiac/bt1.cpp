#include <bits/stdc++.h>
#define maxn 1005
#define ll long long
using namespace std;

ll n, cnt=0;
vector<ll> A, B, C;

int main(){
    //freopen("TRIANGLE.INP", "r", stdin);
    //freopen("TRIANGLE.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    A.resize(n+1);
    B.resize(n+1);
    C.resize(n+1);
    for (ll i=1; i<=n; i++) cin>> A[i];
    for (ll i=1; i<=n; i++) cin>> B[i];
    for (ll i=1; i<=n; i++) cin>> C[i];
    sort(C.begin()+1, C.begin()+1+n);
    for (ll i=1; i<=n; i++){
        for (ll j=1; j<=n; j++){
            ll k1=lower_bound(C.begin()+1, C.begin()+1+n, A[i]+B[j])-C.begin()-1;
            ll k2=upper_bound(C.begin()+1, C.begin()+1+n, abs(A[i]-B[j]))-C.begin();
            cnt+=max(k1-k2+1, 0ll);
        }
    }
    cout<< cnt;
    return 0;
}
