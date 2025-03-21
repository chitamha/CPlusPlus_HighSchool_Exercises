#include <bits/stdc++.h>
#define fi first
#define se second
#define ii pair<int, int>
using namespace std;

int n, m, s, t;
vector<int> d(10005, 1000000000);
vector<ii> adj[10005];

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
    freopen("height.inp", "r", stdin);
    freopen("height.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m>> s>> t;
    for (int i=1; i<=m; i++){
        int x, y, w; cin>> x>> y>> w;
        adj[x].push_back({y, -w+10001});
        adj[y].push_back({x, -w+10001});
    }
    dijkstra(s);
    cout<< 10001-d[t];
    return 0;
}
