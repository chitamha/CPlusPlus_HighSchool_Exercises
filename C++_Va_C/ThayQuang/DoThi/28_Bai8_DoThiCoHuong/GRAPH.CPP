#include <bits/stdc++.h>
#define fi first
#define se second
#define ii pair<int, int>
using namespace std;

int m, s, t;
map<int, vector<ii>> adj;
map<int, int> d;

void dijkstra(int x){
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    d[x]=0;
    pq.push({0, x});
    while (!pq.empty()){
        int u=pq.top().se, dis=pq.top().fi;
        pq.pop();
        if (dis>d[u]) continue;
        for (ii p:adj[u]){
            if (d[p.fi]>max(dis, p.se)){
                d[p.fi]=max(dis, p.se);
                pq.push({d[p.fi], p.fi});
            }
        }
    }
}

int main(){
    freopen("GRAPH.INP", "r", stdin);
    freopen("GRAPH.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> m>> s>> t;
    for (int i=1; i<=m; i++){
        int x, y; cin>> x>> y;
        adj[x].push_back({y, i});
        d[x]=1100000000;
        d[y]=1100000000;
    }
    dijkstra(s);
    if (d[t]==1100000000) cout<< 0;
    else cout<< d[t];
    return 0;
}
