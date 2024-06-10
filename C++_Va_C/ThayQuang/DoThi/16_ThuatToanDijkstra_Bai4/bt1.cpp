#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
using namespace std;
using ll=long long;

ll n, m, s, t;
vector<llll> adj[1005];
vector<ll> d(1005, 1e9);
vector<ll> parent(1005);
vector<ll> path;

void dijkstra(ll i){
    priority_queue<llll, vector<llll>, greater<llll>> Q;
    d[s]=0;
    Q.push({0, s});
    while (!Q.empty()){
        auto top=Q.top(); Q.pop();
        ll kc=top.fi, u=top.se;
        if (kc>d[u]) continue;
        for (auto p:adj[u]){
            ll v=p.fi, w=p.se;
            if (d[v]>d[u]+w){
                d[v]=d[u]+w;
                parent[v]=u;
                Q.push({d[v], v});
            }
        }
    }
}

int main(){
    freopen("GRAPH.INP", "r", stdin);
    freopen("GRAPH.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>> n>> m>> s>> t;
    for (ll i=1; i<=m; i++){
        ll x, y, w;
        cin>> x>> y>> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    dijkstra(s);
    if (d[t]!=1e9){
        cout<< "Duong di ngan nhat la: "<< d[t]<< endl;
        while (s!=t){
            path.push_back(t);
            t=parent[t];
        }
        path.push_back(s);
        reverse(begin(path), end(path));
        for (int i:path){
            cout<< i;
            if (i!=*path.rbegin()) cout<< " -> ";
        }
    } else cout<< "Không có đường đi từ S đến F";
    return 0;
}
