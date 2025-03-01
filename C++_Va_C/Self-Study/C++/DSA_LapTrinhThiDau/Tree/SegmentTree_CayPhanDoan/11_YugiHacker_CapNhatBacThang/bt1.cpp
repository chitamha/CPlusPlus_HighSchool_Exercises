#include <bits/stdc++.h>
#define maxn 200005
#define ll long long
#define fi first
#define se second
using namespace std;

ll n, q, A[maxn], T[maxn*4];
pair<ll, ll> lazy[4*maxn], Manage[4*maxn];
//First: so luong; Second: tong left

ll Inc(ll l, ll r1, ll r2){
    return (r2-r1+1)-(r2-r1+1)*l+r2*(r2+1)/2-(r1-1)*r1/2;
}

ll Inc2(ll id, ll r1, ll r2){
    return lazy[id].fi*(r2-r1+1)+lazy[id].fi*(r2*(r2+1)/2-(r1-1)*r1/2)-(r2-r1+1)*lazy[id].se;
}

void push(ll id){
    T[2*id]+=Inc2(id, Manage[2*id].fi, Manage[2*id].se);
    T[2*id+1]+=Inc2(id, Manage[2*id+1].fi, Manage[2*id+1].se);
    lazy[2*id].fi+=lazy[id].fi;
    lazy[2*id].se+=lazy[id].se;
    lazy[2*id+1].fi+=lazy[id].fi;
    lazy[2*id+1].se+=lazy[id].se;
    lazy[id]={0, 0};
}

void build(ll id, ll l, ll r){
    Manage[id]={l, r};
    if (l==r){
        T[id]=A[l];
        Manage[id]={l, r};
        return;
    }
    ll mid=(l+r)/2;
    build(2*id, l, mid);
    build(2*id+1, mid+1, r);
    T[id]=T[2*id]+T[2*id+1];
}

void update(ll id, ll l, ll r, ll u, ll v){
    if (u>r || v<l) return;
    if (u<=l && r<=v){
        T[id]+=Inc(u, l, r);
        lazy[id].fi++;
        lazy[id].se+=u;
        return;
    }
    ll mid=(l+r)/2;
    push(id);
    update(2*id, l, mid, u, v);
    update(2*id+1, mid+1, r, u, v);
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
    cin>> n;
    for (ll i=1; i<=n; i++) cin>> A[i];
    build(1, 1, n);
    cin>> q;
    while (q--){
        ll typ, u, v;
        cin>> typ>> u>> v;
        if (typ==1) update(1, 1, n, u, v);
        else cout<< get(1, 1, n, u, v)<< "\n";
    }
    return 0;
}
