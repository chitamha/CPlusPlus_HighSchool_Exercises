#include <bits/stdc++.h>
#define ll long long
#define maxn 1000006
using namespace std;

string s;
ll m;
struct node{
    ll ans, open, close;
    friend node operator + (node A, node B){
        node C;
        ll tmp=min(A.open, B.close);
        C.ans=A.ans+B.ans+2*tmp;
        C.open=B.open+A.open-tmp;
        C.close=A.close+B.close-tmp;
        return C;
    }
};
node T[maxn*4];

void build(ll id, ll l, ll r){
    if (l==r){
        if (s[l]=='(') T[id]={0, 1, 0};
        else T[id]={0, 0, 1};
        return;
    }
    ll mid=(l+r)/2;
    build(2*id, l, mid);
    build(2*id+1, mid+1, r);
    T[id]=T[2*id]+T[2*id+1];
}

void update(ll id, ll l, ll r, ll pos, char c){
    if (pos<l || pos>r) return;
    if (l==r){
        if (c=='(') T[id]={0, 1, 0};
        else T[id]={0, 0, 1};
        return;
    }
    ll mid=(l+r)/2;
    update(2*id, l, mid, pos, c);
    update(2*id+1, mid+1, r, pos, c);
    T[id]=T[2*id]+T[2*id+1];
}

node get(ll id, ll l, ll r, ll u, ll v){
    if (u>r || v<l) return {0, 0, 0};
    if (u<=l && r<=v) return T[id];
    ll mid=(l+r)/2;
    node A=get(2*id, l, mid, u, v);
    node B=get(2*id+1, mid+1, r, u, v);
    return A+B;
}

int main(){
    cin>> s;
    ll n=s.size();
    s=' '+s;
    //for (ll i=1; i<=n; i++) update(1, 1, n, i, s[i]);
    build(1, 1, n);
    cin>> m;
    while (m--){
        ll l, r; cin>> l>> r;
        cout<< get(1, 1, n, l, r).ans<< "\n";
    }
    return 0;
}
