#include <bits/stdc++.h>
using namespace std;

int k, n, m, Located[105], visited[1005], Time[1005];
vector<int> adj[1005];

void dfs(int u){
    visited[u]=1;
    Time[u]++;
    for (int v:adj[u]){
        if (!visited[v])
            dfs(v);
    }
}

int main(){
    freopen("HOPMAT.INP", "r", stdin);
    freopen("HOPMAT.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> k>> n>> m;
    for (int i=1; i<=k; i++) cin>> Located[i];
    for (int i=1; i<=m; i++){
        int x, y; cin>> x>> y;
        adj[x].push_back(y);
    }
    for (int i=1; i<=k; i++){
        dfs(Located[i]);
        memset(visited, 0, sizeof visited);
    }
    int ans=0;
    for (int i=1; i<=n; i++){
        if (Time[i]==k){
            //cout<< i<< endl;
            ans++;
        }
    }
    cout<< ans;
    return 0;
}
