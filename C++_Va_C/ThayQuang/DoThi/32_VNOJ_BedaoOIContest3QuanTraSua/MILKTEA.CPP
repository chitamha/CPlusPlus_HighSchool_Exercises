#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define llll pair<ll, ll>
using namespace std;

ll n, m, k, d[100005], RealDis[100005];
vector<llll> adj[100005];
vector<llll> Shop;

void Dijkstra(ll x){
    priority_queue<llll, vector<llll>, greater<llll>> pq;
    d[x]=0;
    pq.push({0, x});
    while (!pq.empty()){
        ll u=pq.top().se, dis=pq.top().fi;
        pq.pop();
        if (dis>d[u]) continue;
        for (llll p:adj[u]){
            ll v=p.fi, w=p.se;
            if (d[v]>d[u]+w){
                d[v]=d[u]+w;
                pq.push({d[v], v});
            }
        }
    }
}

int main(){
    freopen("MILKTEA.INP", "r", stdin);
    freopen("MILKTEA.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m>> k;
    for (ll i=1; i<=m; i++){
        ll u, v, w; cin>> u>> v>> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    for (ll i=1; i<=k; i++){
        ll p, t; cin>> p>> t;
        Shop.push_back({p, t});
    }
    memset(RealDis, 62, sizeof RealDis);
    for (ll i=0; i<k; i++){
        memset(d, 62, sizeof d);
        Dijkstra(Shop[i].fi);
        for (ll j=1; j<=n; j++){
            if (j==Shop[i].fi){
                if (Shop[i].se==0) RealDis[j]=0;
            } else RealDis[j]=min(RealDis[j], d[j]);
        }
    }
    for (ll i=1; i<=n; i++) cout<< RealDis[i]<< " ";
    return 0;
}
