#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, q;
vector<ll> A(100005), Bit1(100005), Bit2(100005);

void updatePoint(ll pos, ll val, vector<ll>& Bit){
    for (; pos<=n; pos+=pos&(-pos))
        Bit[pos]+=val;
}

void updateRange(ll u, ll v, ll val){
    updatePoint(u, val, Bit2);
    updatePoint(v+1, -val, Bit2);
    updatePoint(u, (n-u+1)*val, Bit1);
    updatePoint(v+1, -(n-v)*val, Bit1);
}

ll get(ll pos, vector<ll> Bit){
    ll sum=0;
    for (; pos>=1; pos-=pos&(-pos))
        sum+=Bit[pos];
    return sum;
}

ll preS(ll pos){
    return get(pos, Bit1)-(n-pos)*get(pos, Bit2);
}

ll rangeSum(ll l, ll r){
    return preS(r)-preS(l-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> q;
    for (ll i=1; i<=n; i++){
        cin>> A[i];
        updateRange(i, i, A[i]);
    }
    //for (ll i=1; i<=n; i++) cout<< get(i, Bit2)<< " "; cout<< endl;
    while (q--){
        ll typ, u, v, x;
        cin>> typ>> u>> v;
        if (typ==1){
            cin>> x;
            updateRange(u, v, x);
        } else cout<< rangeSum(u, v)<< "\n";
    }
    return 0;
}
