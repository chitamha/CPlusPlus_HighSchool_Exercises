#include <bits/stdc++.h>
#define ll long long
#define maxn 1000006
using namespace std;

ll n, m, s;
vector<pair<ll, ll>> adj[maxn];
vector<ll> d(maxn, 1e9);

void dijkstra(ll s){
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<int, int>>> Q;
    Q.push({0, s});
    d[s]=0;
    while (!Q.empty()){
        auto top=Q.top(); Q.pop();
        ll kc=top.first, u=top.second;
        if (kc>d[u]) continue;
        for (auto p:adj[u]){
            ll v=p.first, w=p.second;
            if (d[v]>d[u]+w){
                d[v]=d[u]+w;
                Q.push({d[v], v});
            }
        }
    }
    for (ll i=1; i<=n; i++){
        cout<< d[i]<< " ";
    }
    cout<< endl;
}

int main(){
    freopen("DIJKSTRA.INP", "r", stdin);
    freopen("DIJKSTRA.OUT", "w", stdout);
    cin>> n>> m>> s;
    for (ll i=1; i<=m; i++){
        int u, v, w;
        cin>> u>> v>> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dijkstra(s);
    return 0;
}
