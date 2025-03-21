#include <bits/stdc++.h>
#define fi first
#define se second
#define ii pair<int, int>
using namespace std;

int n, m;
vector<int> d(300005, 1000000000);
vector<ii> adj[300005];

void dijkstra(int x){
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    d[x]=0;
    pq.push({0, x});
    while (!pq.empty()){
        int u=pq.top().se, dis=pq.top().fi;
        pq.pop();
        if (dis>d[u]) continue;
        for (ii p:adj[u]){
            int v=p.fi, w=p.se;
            if (d[v]>max(dis, w)){
                d[v]=max(dis, w);
                pq.push({d[v], v});
            }
        }
    }
}

int main(){
    freopen("COMNET.INP", "r", stdin);
    freopen("COMNET.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m;
    for (int i=1; i<=m; i++){
        int x, y, w; cin>> x>> y;
        adj[x].push_back({y, i});
    }
    dijkstra(1);
    if (d[n]==1000000000) cout<< -1;
    else cout<< d[n];
    return 0;
}
