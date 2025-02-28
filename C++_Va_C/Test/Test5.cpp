#include <bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;

ll n, q, A[maxn], T[maxn*4], lazy[4*maxn];

void push(ll id){
    T[2*id]+=lazy[id];
    T[2*id+1]+=lazy[id];
    lazy[2*id]+=lazy[id];
    lazy[2*id+1]+=lazy[id];
    lazy[id]=0;
}

void update(ll id, ll l, ll r, ll u, ll v, ll val){
    if (u>r || v<l) return;
    if (u<=l && r<=v){
        T[id]+=(r-l+1)*val;
        lazy[id]+=val;
        return;
    }
    ll mid=(l+r)/2;
    push(id);
    update(2*id, l, mid, u, v, val);
    update(2*id+1, mid+1, r, u, v, val);
    T[id]=T[2*id]+T[2*id+1];
}

ll get(ll id, ll l, ll r, ll u, ll v){
    if (u>r || v<l) return 0;
    if (u<=l && r<=v) return T[id];
    ll mid=(l+r)/2;
    push(id);
    return get(2*id, l, mid, u, v)+get(2*id+1, mid+1, r, u, v);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> q;
    for (ll i=1; i<=n; i++){
        cin>> A[i];
        update(1, 1, n, i, i, A[i]);
    }
    while (q--){
        ll typ, u, v, x;
        cin>> typ>> u>> v;
        if (typ==1){
            cin>> x;
            update(1, 1, n, u, v, x);
        } else cout<< get(1, 1, n, u, v)<< "\n";
    }
    return 0;
}
