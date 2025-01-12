#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 100006
using namespace std;

ll t, n, k;
vector<ll> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> t;
    while (t--){
        cin>> n>> k;
        v.resize(n+1);
        for (ll i=1; i<=n; i++) cin>> v[i];
        deque<ll> dq;
        for (ll i=1; i<=n; i++){
            while (!dq.empty() && v[i]<=v[dq.back()]) dq.pop_back();
            dq.push_back(i);
            if (dq.front()<i-k+1) dq.pop_front();
            if (i>=k) cout<< v[dq.front()]<< " ";
        }
        cout<< endl;
        v.clear();
    }
    return 0;
}
