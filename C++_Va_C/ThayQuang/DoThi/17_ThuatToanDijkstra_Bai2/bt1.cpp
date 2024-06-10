#include <bits/stdc++.h>
#define ll long long
#define maxn 1000006
using namespace std;

ll n, m, s, t;
vector<pair<ll, ll>> adj[maxn];
vector<ll> d(maxn, 1e9);
vector<ll> parent(maxn);
vector<ll> path;

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
                parent[v]=u;
                d[v]=d[u]+w;
                Q.push({d[v], v});
            }
        }
    }
}

int main(){
    freopen("GRAPH.INP", "r", stdin);
    freopen("GRAPH.OUT", "w", stdout);
    cin>> n>> m>> s>> t;
    for (ll i=1; i<=m; i++){
        int u, v, w;
        cin>> u>> v>> w;
        adj[u].push_back({v, w});
    }
    dijkstra(s);
    cout<< d[t]<< endl;
    while (t!=s){
        path.push_back(t);
        t=parent[t];
    }
    path.push_back(s);
    reverse(begin(path), end(path));
    for (ll i:path) cout<< i<< " ";
    return 0;
}
