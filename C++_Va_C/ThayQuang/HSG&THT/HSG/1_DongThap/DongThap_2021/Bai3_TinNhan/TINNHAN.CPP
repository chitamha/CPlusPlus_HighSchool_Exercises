#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 1000006
using namespace std;

int n, m, cnt=0, visited[maxn];
vector<int> adj[maxn];

void Dfs(int u){
    visited[u]=1;
    for (int v:adj[u]){
        if (!visited[v]){
            Dfs(v);
        }
    }
}

int main(){
    freopen("TINNHAN.INP", "r", stdin);
    freopen("TINNHAN.OUT", "w", stdout);
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
            Dfs(i);
            cnt++;
        }
    }
    cout<< cnt;
    return 0;
}
