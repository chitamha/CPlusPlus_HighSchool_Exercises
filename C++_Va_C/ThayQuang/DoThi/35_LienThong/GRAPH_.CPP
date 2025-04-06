#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
using namespace std;

int n, m, timeDFS=0, id[20005], low[20005], Khop[20005], stplt=0;
vector<int> adj[20005];

void DFS(int u, int p){
    id[u]=low[u]=++timeDFS;
    int node=(p!=u);
    for (int v:adj[u]){
        if (v==p) continue;
        if (id[v]==0){
            DFS(v, u);
            low[u]=min(low[u], low[v]);
            //if (low[v]>=id[v]) cau++;
            if (low[v]>=id[u]) node++;
        } else low[u]=min(low[u], id[v]);
    }
    if (node>=2){
        if (p!=u) Khop[u]=node-1;
        else Khop[u]=node-1;
    }
}

int main(){
    freopen("GRAPH_.INP", "r", stdin);
    freopen("GRAPH_.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m;
    for (int i=1; i<=m; i++){
        int u, v; cin>> u>> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i=1; i<=n; i++){
        if (id[i]==0){
            stplt++;
            DFS(i, i);
        }
    }
    for (int i=1; i<=n; i++){
        if (Khop[i]==0){
            if (adj[i].size()!=0) cout<< stplt<< "\n";
            else cout<< stplt-1<< "\n";
        } else cout<< stplt+Khop[i]<< "\n";
    }
    return 0;
}
