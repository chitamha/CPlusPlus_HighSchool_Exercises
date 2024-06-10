#include <bits/stdc++.h>
#define ll long long
#define maxn 1000006
using namespace std;

ll t, n, k, cnt=0;
vector<ll> v;
ll X[maxn];
vector<vector<ll>> vv;

void xuli(ll i){
    vector<ll> vll;
    for (ll j=1; j<=i; j++)
        if (X[j]) vll.push_back(v[j]);
    vv.push_back(vll);
}

void ql(ll i, ll sum){
    cnt++;
    if (sum>k || i>n) return;
    for (ll j=0; j<=1; j++){
        X[i]=j;
        if (X[i]) sum+=v[i];
        if (sum==k) xuli(i);
        else ql(i+1, sum);
    }
}

int main(){
    cin>> t;
    while (t--){
        cin>> n>> k;
        v.resize(n+1);
        for (ll i=1; i<=n; i++) cin>> v[i];
        sort(v.begin(), v.end());
        ql(1, 0);
        sort(vv.begin(), vv.end());
        for (vector<ll> vt:vv){
            cout<< "[";
            for (ll x:vt){
                cout<< x;
                if (x!=*(vt.rbegin())) cout<< " ";
            }
            cout<< "] ";
        }
        cout<< endl<< cnt<< endl;
        cnt=0;
        v.clear();
        vv.clear();
        memset(X, 0, sizeof X);
    }
    return 0;
}

/*
#include <bits/stdc++.h>
#define ll long long
#define maxn 1000006
using namespace std;

ll t, n, k, cnt=0;
vector<ll> v;
ll X[maxn];

void xuli(ll i){
    cout<< "[";
    for (ll j=1; j<=i; j++){
        if (X[j]){
            cout<< v[j];
            if (j!=i) cout<< " ";
        }
    }
    cout<< "]"<< endl;
}

void ql(ll i, ll sum){
    cnt++;
    if (sum>k || i>n) return;
    for (ll j=1; j>=0; j--){
        X[i]=j;
        if (X[i]) sum+=v[i];
        if (sum==k) xuli(i);
        else ql(i+1, sum);
        sum-=v[i];
    }
}

int main(){
    cin>> t;
    while (t--){
        cin>> n>> k;
        v.resize(n+1);
        for (ll i=1; i<=n; i++) cin>> v[i];
        sort(v.begin(), v.end());
        ql(1, 0);
        cout<< cnt<< endl;
        cnt=0;
        v.clear();
        memset(X, 0, sizeof X);
    }
    return 0;
}
*/
