#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 200006
using namespace std;

int n, q, A[maxn];
ll T[maxn*4], lazy[maxn*4];

void push(int id){
    if (lazy[id]!=0){
        T[2*id]+=lazy[id];
        T[2*id+1]+=lazy[id];
        lazy[2*id]+=lazy[id];
        lazy[2*id+1]+=lazy[id];
        lazy[id]=0;
    }
}

void build(int id, int l, int r){
    if (l==r){
        T[id]=A[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*id, l, mid);
    build(2*id+1, mid+1, r);
    T[id]=min(T[id*2], T[id*2+1]);
}

void update(int id, int l, int r, int u, int v, int value){
    if (u>r || v<l) return;
    if (u<=l && r<=v){
        T[id]+=value;
        lazy[id]+=value;
        return;
    }
    int mid=(l+r)/2;
    push(id);
    update(2*id, l, mid, u, v, value);
    update(2*id+1, mid+1, r, u, v, value);
    T[id]=min(T[id*2], T[id*2+1]);
}

ll get(int id, int l, int r, int u, int v){
    if (u>r || v<l) return 1e18;
    if (u<=l && r<=v) return T[id];
    int mid=(l+r)/2;
    push(id);
    return min(get(2*id, l, mid, u, v), get(2*id+1, mid+1, r, u, v));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> q;
    for (int i=1; i<=n; i++){
        cin>> A[i];
        update(1, 1, n, i, i, A[i]);
    }
    //build(1, 1, n);
    while (q--){
        int t, u, v;
        cin>> t>> u>> v;
        if (t==1){
            int x; cin>> x;
            update(1, 1, n, u, v, x);
        } else cout<< get(1, 1, n, u, v)<< "\n";
    }
    return 0;
}
/*
INPUT:
5 5
5 1 4 2 3
2 1 4
2 2 4
1 1 5 3
2 2 4
2 1 2
OUTPUT:
1
1
4
4
*/
