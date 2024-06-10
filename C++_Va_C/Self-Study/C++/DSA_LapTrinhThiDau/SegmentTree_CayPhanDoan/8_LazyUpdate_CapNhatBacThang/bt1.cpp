#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 1000006
using namespace std;

int n, q, A[maxn];
ll T[maxn*4], lazy[maxn*4];
pair<int, int> infnode[maxn*4];

ll inc(int l, int r){
    int tmp=l-2;
    l-=tmp; r-=tmp;
    ll ans=(1ll*pow(r, 2)-1ll*pow(l, 2)+r+l)/2;
    return ans;
}

void push(int id){
    if (lazy[id]!=0){
        pair<int, int> tmp1=infnode[2*id];
        pair<int, int> tmp2=infnode[2*id+1];
        T[2*id]+=lazy[id]*inc(tmp1.fi, tmp1.se);
        T[2*id+1]+=lazy[id]*inc(tmp2.fi, tmp2.se);
        lazy[2*id]+=lazy[id];
        lazy[2*id+1]+=lazy[id];
        lazy[id]=0;
    }
}

void build(int id, int l, int r){
    infnode[id]={l, r};
    if (l==r){
        T[id]=A[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*id, l, mid);
    build(2*id+1, mid+1, r);
    T[id]=T[id*2]+T[id*2+1];
}

void update(int id, int l, int r, int u, int v){
    if (u>r || v<l) return;
    if (u<=l && r<=v){
        T[id]+=inc(l, r);
        lazy[id]++;
        return;
    }
    int mid=(l+r)/2;
    push(id);
    update(2*id, l, mid, u, v);
    update(2*id+1, mid+1, r, u, v);
    T[id]=T[id*2]+T[id*2+1];
}

ll get(int id, int l, int r, int u, int v){
    if (u>r || v<l) return 0;
    if (u<=l && r<=v) return T[id];
    int mid=(l+r)/2;
    push(id);
    return get(2*id, l, mid, u, v)+get(2*id+1, mid+1, r, u, v);
}

int main(){
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    for (int i=1; i<=n; i++) cin>> A[i];
    build(1, 1, n);
    cin>> q;
    while (q--){
        int type, l, r;
        cin>> type>> l>> r;
        if (type==1) update(1, 1, n, l, r);
        else cout<< get(1, 1, n, l, r)<< "\n";
    }
    return 0;
}
