#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 10006
using namespace std;

int n, m, khop, cau, cnt=0;
vector<int> adj[maxn*5];
int id[maxn], low[maxn];

void DFS(int u, int p){
    id[u]=low[u]=++cnt;
    int node = (p!=0);
    for (int v:adj[u]){
        if (v==p) continue;
        if (id[v]) low[u]=min(low[u], id[v]);
        else{
            DFS(v, u);
            low[u]=min(low[u], low[v]);
            if (low[v]>id[u]) cau++; //low[v]>id[u] || low[v]==id[v]
            if (low[v]>=id[u]) node++;
        }
    }
    if (node>=2) khop++;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m;
    for (int i=1; i<=m; i++){
        int u, v; cin>> u>> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i=1; i<=n; i++){
        if (id[i]==0) DFS(i, 0);
    }
    cout<< khop<< " "<< cau;
    return 0;
}
