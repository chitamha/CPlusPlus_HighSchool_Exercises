#include <bits/stdc++.h>
#define ll long long
#define maxn 1000006
using namespace std;

ll t, n, k, cnt=0;
vector<ll> v;
ll X[maxn];
vector<vector<ll>> vv;

void xuli(){
    ll sum=0;
    vector<ll> temp;
    for (ll i=1; i<=n; i++){
        if (X[i]) sum+=v[i];
    }
    if (sum==k){
         for (ll i=1; i<=n; i++)
            if (X[i]) temp.push_back(v[i]);
        vv.push_back(temp);
    }
}

void ql(ll i){
    cnt++;
    for (ll j=0; j<=1; j++){
        X[i]=j;
        if (i==n){
            xuli();
        } else ql(i+1);
    }
}

int main(){
    cin>> t;
    while (t--){
        cin>> n>> k;
        v.resize(n+1);
        for (ll i=1; i<=n; i++) cin>> v[i];
        sort(v.begin(), v.end());
        ql(1);
        cout<< cnt<< endl;
        sort(vv.begin(), vv.end());
        for (auto vt:vv){
            cout<< "[";
            for (ll x:vt){
                cout<< x;
                if (x!=*(vt.rbegin()))
                    cout<< " ";
            }
            cout<< "] ";
        }
        cout<< endl;
        cnt=0;
        memset(X, 0, sizeof X);
        v.clear();
        vv.clear();
    }
    return 0;
}
