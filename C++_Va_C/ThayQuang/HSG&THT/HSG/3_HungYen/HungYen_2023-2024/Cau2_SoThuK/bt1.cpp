#include <bits/stdc++.h>
#define ll unsigned long long
#define maxn 100005
using namespace std;

ll n, t, A[maxn], dis[maxn];

int main(){
    cin>> n>> t;
    A[0]=0; A[n+1]=1e18+1e6;
    for (ll i=1; i<=n; i++) cin>> A[i];
    sort(A, A+n+2);
    dis[0]=A[1]-A[0]-1;
    for (ll i=1; i<=n; i++){
        dis[i]=dis[i-1]+A[i+1]-A[i]-1;
    }
    while (t--){
        ll k; cin>> k;
        int id=lower_bound(dis, dis+n+1, k)-dis;
        if (id>=1) cout<< k-dis[id-1]+A[id]<< endl;
        else cout<< k<< endl;
    }
    return 0;
}
