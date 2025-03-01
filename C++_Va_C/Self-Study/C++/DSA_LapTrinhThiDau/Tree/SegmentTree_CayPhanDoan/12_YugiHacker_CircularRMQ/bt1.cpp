#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 200005
using namespace std;

ll n, q, cnt, lf, rg, inc, A[maxn], T[4*maxn], lazy[4*maxn];

void Split(string s){
    lf=rg=inc=0;
    cnt=2;
    ll siz=s.size(), duong=1;
    s='@'+s;
    ll i=1;
    while (s[i]!=' ') lf=lf*10+int(s[i])-48, i++;
    while (s[i]==' ') i++;
    while (i<=siz && s[i]!=' ') rg=rg*10+int(s[i])-48, i++;
    while (i<=siz && s[i]==' ') i++;
    if (i<=siz && s[i]=='-') duong=-1, i++;
    while (i<=siz && s[i]!=' ') inc=inc*10+int(s[i])-48, i++, cnt=3;
    inc*=duong;
    lf++; rg++;
}

void push(ll id){
    T[2*id]+=lazy[id];
    T[2*id+1]+=lazy[id];
    lazy[2*id]+=lazy[id];
    lazy[2*id+1]+=lazy[id];
    lazy[id]=0;
}

void update(ll id, ll l, ll r, ll u, ll v, ll val){
    if (r<u || v<l) return;
    if (u<=l && r<=v){
        T[id]+=val;
        lazy[id]+=val;
        return;
    }
    ll mid=(l+r)/2;
    push(id);
    update(2*id, l, mid, u, v, val);
    update(2*id+1, mid+1, r, u, v, val);
    T[id]=min(T[2*id], T[2*id+1]);
}

ll get(ll id, ll l, ll r, ll u, ll v){
    if (r<u || v<l) return 1e18;
    if (u<=l && r<=v) return T[id];
    ll mid=(l+r)/2;
    push(id);
    return min(get(2*id, l, mid, u, v), get(2*id+1, mid+1, r, u, v));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    for (ll i=1; i<=n; i++){
        cin>> A[i];
        update(1, 1, n, i, i, A[i]);
    }
    cin>> q;
    cin.ignore();
    while (q--){
        string s;
        getline(cin, s);
        Split(s);
        if (cnt==2){
            if (lf<=rg) cout<< get(1, 1, n, lf, rg)<< "\n";
            else cout<< min(get(1, 1, n, lf, n), get(1, 1, n, 1, rg))<< "\n";
        }
        else{
            if (lf<=rg) update(1, 1, n, lf, rg, inc);
            else update(1, 1, n, lf, n, inc), update(1, 1, n, 1, rg, inc); {}
        }
    }
    return 0;
}
