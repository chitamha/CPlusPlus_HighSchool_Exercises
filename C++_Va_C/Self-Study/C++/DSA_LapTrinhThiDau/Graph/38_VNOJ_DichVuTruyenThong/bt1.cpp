#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
using namespace std;

ll n, m, k, d[505], use[505];
vector<pair<ll, ll>> adj[505];

void dijkstra(ll i){
    priority_queue<llll, vector<llll>, greater<llll>> pq;
    d[i]=0;
    pq.push({0, i});
    while (!pq.empty()){
        ll u=pq.top().se;
        ll kc=pq.top().fi;
        pq.pop();
        if (kc>d[u] || use[u]==0) continue;
        for (auto p:adj[u]){
            ll v=p.fi, w=p.se;
            if (d[v]>d[u]+w){
                d[v]=d[u]+w;
                if (use[v]) pq.push({d[v], v});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m>> k;
    for (ll i=1; i<=m; i++){
        ll u, v, w; cin>> u>> v>> w;
        adj[u].push_back({v, w});
    }
    while (k--){
        ll type; cin>> type;
        if (type==1){
            ll x; cin>> x;
            use[x]=1;
        } else{
            ll s, t; cin>> s>> t;
            bool check=0;
            if (use[s]==0){
                use[s]=1;
                check=1;
            }
            for (ll i=1; i<=n; i++) d[i]=1000000000000000000;
            dijkstra(s);
            if (d[t]!=1000000000000000000) cout<< d[t]<< "\n";
            else cout<< -1<< "\n";
            if (check) use[s]=0;
        }
    }
    return 0;
}
