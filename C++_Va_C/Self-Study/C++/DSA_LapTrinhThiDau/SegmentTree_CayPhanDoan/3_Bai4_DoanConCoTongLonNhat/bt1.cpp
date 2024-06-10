#include <bits/stdc++.h>
#define ll long long
#define maxn 200005
using namespace std;

ll n, q, k, x, A[maxn];
struct node{
    ll sum, Max, pre, suf;
    node(){}
    node(ll value): sum(value), Max(max(0ll, value)), pre(max(0ll, value)), suf(max(0ll, value)) {}
    /*
    node(ll value){
        sum=value; Max=max(0ll, value);
        pre=max(0ll, value); suf=max(0ll, value);
    }
    */
    friend node operator + (node A, node B){
        node C;
        C.sum=A.sum+B.sum;
        C.Max=max({A.suf+B.pre, A.suf+B.sum, A.sum+B.pre, A.sum+B.sum, A.Max, B.Max});
        C.pre=max(A.pre, A.sum+B.pre);
        C.suf=max(A.suf+B.sum, B.suf);
        return C;
    }
};
node T[4*maxn];

void build(ll id, ll l, ll r){
    if (l==r){
        T[id]=node(A[l]);
        return;
    }
    ll mid=(l+r)/2;
    build(2*id, l, mid);
    build(2*id+1, mid+1, r);
    T[id]=T[2*id]+T[2*id+1];
}

node get(ll id, ll l, ll r, ll u, ll v){
    if (u>r || v<l) return node(0);
    if (u<=l && r<=v) return T[id];
    ll mid=(l+r)/2;
    node ans=get(2*id, l, mid, u, v)+get(2*id+1, mid+1, r, u, v);
    return ans;
}

void update(ll id, ll l, ll r, ll pos, ll value){
    if (pos<l || pos>r) return;
    if (l==r){
        A[pos]=value;
        T[id]=node(value);
        return;
    }
    ll mid=(l+r)/2;
    update(2*id, l, mid, pos, value);
    update(2*id+1, mid+1, r, pos, value);
    T[id]=T[2*id]+T[2*id+1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> q;
    for (ll i=1; i<=n; i++){
        cin>> A[i];
        //update(1, 1, n, i, A[i]);
    }
    build(1, 1, n);
    while (q--){
        cin>> k>> x;
        update(1, 1, n, k, x);
        //for (ll i=1; i<=n; i++) cout<< A[i]<< " ";
        //cout<< "\n";
        //node ans=get(1, 1, n, 1, n);
        //cout<< ans.Max<< "\n";
        cout<< T[1].Max<< "\n";
    }
    return 0;
}
