#include <bits/stdc++.h>
#define ii pair<int, int>
#define ll long long
#define fi first
#define se second
using namespace std;

int n, m, visited[300];
vector<int> adj[300];

void dfs(int u){
    visited[u]=1;
    for (int v:adj[u]){
        if (!visited[v])
            dfs(v);
    }
}

int main(){
    freopen("cow.inp", "r", stdin);
    freopen("cow.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m;
    for (int i=1; i<=m; i++){
        int x, y; cin>> x>> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1);
    int check=0;
    for (int i=1; i<=n; i++) if (visited[i]==0) check=1, cout<< i<< "\n"; {}
    if (check==0) cout<< 0;
    return 0;
}
