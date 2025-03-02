#include <bits/stdc++.h>
#define MOD 65536
#define ll long long
using namespace std;

ll seed, mul, add, n, k, ans=0, A[250005], Bit[65540];

void update(ll pos, ll val){
    for (; pos<=65536; pos+=pos&(-pos))
        Bit[pos]+=val;
}

ll get(ll pos){
    ll sum=0;
    for (; pos>=1; pos-=pos&(-pos))
        sum+=Bit[pos];
    return sum;
}

ll Find(int i){
    ll l=1, r=65536, mid;
    while (l<=r){
        mid=(l+r)/2;
        if (get(mid)>=(k+1)/2) r=mid-1;
        else l=mid+1;
    }
    return r;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>> t;
    for (int q=1; q<=t; q++){
    cin>> seed>> mul>> add>> n>> k;
    A[1]=seed;
    for (ll i=2; i<=n; i++) A[i]=(A[i-1]*mul+add)%MOD;
    for (ll i=1; i<=k; i++) update(A[i]+1, 1);
    ans+=Find(k);
    for (ll i=k+1; i<=n; i++){
        update(A[i-k]+1, -1);
        update(A[i]+1, 1);
        ans+=Find(i);
    }
    cout<< "Case #"<< q<< ": "<< ans<< "\n";
    memset(A, 0, sizeof A);
    memset(Bit, 0, sizeof Bit);
    ans=0;
    }
    return 0;
}
