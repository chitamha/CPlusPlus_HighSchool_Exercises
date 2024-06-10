#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 5005
#define ii pair<ll, ll>
#define ll long long
using namespace std;

ll n, m, d[maxn], f[maxn];
vector<pair<ll, ll>> adj[maxn];

void dijkstra(ll i){
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    d[i]=0;
    pq.push({0, i});
    while (!pq.empty()){
        ll u=pq.top().se;
        ll kc=pq.top().fi;
        pq.pop();
        if (kc>=d[u]) continue;
        for (auto p:adj[u]){
            ll v=p.fi, w=p.se;
            if (d[v]==d[u]+w){
                f[v]+=f[u];
                pq.push({d[v], v});
            } else if (d[v]>d[u]+w){
                d[v]=d[u]+w;
                f[v]=f[u];
                pq.push({d[v], v});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    memset(d, 62, sizeof d);
    f[1]=1;
    cin>> n>> m;
    for (ll i=1; i<=m; i++){
        ll k, u, v, l;
        cin>> k>> u>> v>> l;
        adj[u].push_back({v, l});
        if (k==2) adj[v].push_back({u, l});
    }
    dijkstra(1);
    cout<< d[n]<< " "<< f[n];
    return 0;
}
