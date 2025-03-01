#include <bits/stdc++.h>
#define ll long long
#define maxn 200005
using namespace std;

int n, q, t, a, b, A[maxn];
ll T[4*maxn];

void build(int id, int l, int r){
    if (l==r){
        T[id]=A[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*id, l, mid);
    build(2*id+1, mid+1, r);
    T[id]=T[2*id]+T[2*id+1];
}

ll get(int id, int l, int r, int u, int v){
    if (u>r || v<l) return 0;
    if (u<=l && r<=v) return T[id];
    int mid=(l+r)/2;
    long long t1=get(2*id, l, mid, u, v);
    long long t2=get(2*id+1, mid+1, r, u, v);
    return t1+t2;
}

void update(int id, int l, int r, int pos, int value){
    if (pos<l || pos>r) return;
    if (l==r){
        T[id]=value;
        A[pos]=value;
        return;
    }
    int mid=(l+r)/2;
    update(2*id, l, mid, pos, value);
    update(2*id+1, mid+1, r, pos, value);
    T[id]=T[2*id]+T[2*id+1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> q;
    for (int i=1; i<=n; i++){
        cin>> A[i];
        //update(1, 1, n, i, A[i]);
    }
    build(1, 1, n);
    while (q--){
        cin>> t>> a>> b;
        if (t==1) update(1, 1, n, a, b);
        else cout<< get(1, 1, n, a, b)<< "\n";
    }
    return 0;
}
