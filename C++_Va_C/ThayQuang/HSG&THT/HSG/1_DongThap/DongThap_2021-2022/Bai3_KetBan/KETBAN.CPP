#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 1000006
using namespace std;

int n, k, m, cnt=0, visited[maxn];
vector<int> adj[maxn];

void Dfs(int u){
    visited[u]=1;
    cnt++;
    for (int v:adj[u]){
        if (!visited[v]){
            Dfs(v);
        }
    }
}

int main(){
    freopen("KETBAN.INP", "r", stdin);
    freopen("KETBAN.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> k>> m;
    for (int i=1; i<=m; i++){
        int u, v; cin>> u>> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Dfs(k);
    cout<< cnt-1;
    return 0;
}
