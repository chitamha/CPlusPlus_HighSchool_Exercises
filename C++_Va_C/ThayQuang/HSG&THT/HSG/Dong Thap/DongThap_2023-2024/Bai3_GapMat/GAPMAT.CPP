#include <bits/stdc++.h>
#define fi first
#define se second
#define ii pair<int, int>
#define ll long long
#define maxn 30006
using namespace std;

int n, m;
ll d[maxn], d1[maxn], dn[maxn];
vector<ii> adj[maxn];

void dijkstra(int i){
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    d[i]=0;
    pq.push({0, i});
    while (!pq.empty()){
        int u=pq.top().se;
        ll kc=pq.top().fi;
        pq.pop();
        if (kc>d[u]) continue;
        for (auto p:adj[u]){
            int v=p.fi, w=p.se;
            if (d[v]>d[u]+w){
                d[v]=d[u]+w;
                pq.push({d[v], v});
            }
        }
    }
}

int main(){
    freopen("GAPMAT.INP", "r", stdin);
    freopen("GAPMAT.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m;
    for (int i=1; i<=m; i++){
        int u, v, c; cin>> u>> v>> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }
    map<ll, ll> mp;
    memset(d, 62, sizeof d);
    dijkstra(1);
    for (int i=1; i<=n; i++) d1[i]=d[i];
    memset(d, 62, sizeof d);
    dijkstra(n);
    for (int i=1; i<=n; i++) dn[i]=d[i];
    ll Min=1e18;
    for (int i=1; i<=n; i++){
        mp[d1[i]+dn[i]]++;
        Min=min(Min, d1[i]+dn[i]);
    }
    cout<< mp[Min];
    return 0;
}
