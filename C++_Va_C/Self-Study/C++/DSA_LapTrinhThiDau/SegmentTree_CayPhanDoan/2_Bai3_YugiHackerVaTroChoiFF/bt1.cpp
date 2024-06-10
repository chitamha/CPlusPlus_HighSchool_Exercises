#include <bits/stdc++.h>
#define ll long long
#define maxn 100005
using namespace std;

ll n, q, t;
ll A[maxn];
struct point{
    long long max1, max2;
};
point T[4*maxn];

point process(point A, point B){
    vector<ll> v;
    v.push_back(A.max1); v.push_back(A.max2);
    v.push_back(B.max1); v.push_back(B.max2);
    sort(v.begin(), v.end(), greater<ll>());
    point ans={v[0], v[1]}; v.clear();
    return ans;
}

void build(ll id, ll l, ll r){
    if (l==r){
        T[id]={A[l], 1};
        //cout<< id<< " "<< l<< " "<< r<< " "<< T[id].max1<< " "<< T[id].max2<< endl;
        return;
    }
    ll mid=(l+r)/2;
    build(2*id, l, mid);
    build(2*id+1, mid+1, r);
    T[id]=process(T[2*id], T[2*id+1]);
    //cout<< id<< " "<< l<< " "<< r<< " "<< T[id].max1<< " "<< T[id].max2<< endl;
}

point get(ll id, ll l, ll r, ll u, ll v){
    if (u>r || v<l) return {1, 1};
    if (u<=l && r<=v) return T[id];
    ll mid=(l+r)/2;
    return process(get(2*id, l, mid, u, v), get(2*id+1, mid+1, r, u, v));
}

void update(ll id, ll l, ll r, ll pos, ll value){
    if (pos>r || pos<l) return;
    if (r==l){
        A[pos]=value;
        T[id]={value, 1};
        return;
    }
    ll mid=(l+r)/2;
    update(id*2, l, mid, pos, value);
    update(id*2+1, mid+1, r, pos, value);
    T[id]=process(T[2*id], T[2*id+1]);
}

ll mod(ll a, ll b, ll MOD){
    if (b==0) return 0;
    ll t=mod(a, b/2, MOD)*2;
    if (b%2==1) t+=a;
    return t%MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    for (ll i=1; i<=n; i++){
        cin>> A[i];
        //update(1, 1, n, i, A[i]);
    }
    build(1, 1, n);
    cin>> q;
    while (q--){
        cin>> t;
        if (t==0){
            ll x, v; cin>> x>> v;
            update(1, 1, n, x, v);
        } else{
            ll l, r, MOD; cin>> l>> r>> MOD;
            if (l==r){
                cout<< mod(A[l], 1, MOD)<< "\n";
                continue;
            }
            point ans=get(1, 1, n, l, r);
            cout<< mod(ans.max1, ans.max2, MOD)<< "\n";
        }
    }
    return 0;
}
