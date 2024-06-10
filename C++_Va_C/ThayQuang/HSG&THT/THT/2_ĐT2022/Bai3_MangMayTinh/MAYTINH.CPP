#include <bits/stdc++.h>
#define maxn 100006
using namespace std;

int n, m, cnt=0, ma=0, visited[maxn];
vector<int> adj[maxn];

void dfs(int u){
    cnt++;
    visited[u]=1;
    for (int v:adj[u]){
        if (visited[v]==0) dfs(v);
    }
}

int main(){
    freopen("MAYTINH.INP", "r", stdin);
    freopen("MAYTINH.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m;
    for (int i=1; i<=m; i++){
        int u, v; cin>> u>> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i=1; i<=n; i++){
        if (visited[i]==0){
            cnt=0;
            dfs(i);
            ma=max(ma, cnt);
        }
    }
    cout<< ma;
    return 0;
}
