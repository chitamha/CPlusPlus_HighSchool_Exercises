#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int n, m, id[50005], low[50005], d[50005], far[50005], timeDFS=0, cnt=0;
vector<int> adj[50005], CH[50005];
vector<pair<int, int>> Vec;

void DFS(int u){
    id[u]=1;
    for (int v:adj[u]){
        if (id[v]==0){
            d[v]=d[u]+1;
            far[v]=u;
            DFS(v);
        }
    }
}

void Tarjan(int u){
    id[u]=low[u]=++timeDFS;
    for (int v:CH[u]){
        if (id[v]) low[u]=min(low[u], id[v]);
        else{
            Tarjan(v);
            low[u]=min(low[u], low[v]);
        }
    }
    if (id[u]==low[u]) cnt++;
}

int main(){
    freopen("ONEWAY.INP", "r", stdin);
    freopen("ONEWAY.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m;
    for (int i=1; i<=m; i++){
        int u, v; cin>> u>> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        Vec.push_back({u, v});
    }
    for (int i=1; i<=n; i++){
        if (id[i]==0) DFS(i);
    }
    for (pair<int, int> p:Vec){
        int u=p.fi, v=p.se;
        if (far[v]==u) CH[u].push_back(v);
        else if (far[u]==v) CH[v].push_back(u);
        else if (d[u]<d[v]) CH[v].push_back(u);
        else CH[u].push_back(v);
    }
    memset(id, 0, sizeof id);
    for (int i=1; i<=n; i++){
        if (id[i]==0) Tarjan(i);
    }
    if (cnt!=1) cout<< 0;
    else{
        cout<< 1<< "\n";
        for (int u=1; u<=n; u++){
            for (int v:CH[u]) cout<< u<< " "<< v<< "\n";
        }
    }
    return 0;
}
