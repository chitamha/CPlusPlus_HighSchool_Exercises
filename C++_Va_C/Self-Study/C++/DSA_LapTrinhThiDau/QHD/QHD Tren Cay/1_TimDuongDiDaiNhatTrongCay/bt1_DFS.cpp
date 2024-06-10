#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 10006
using namespace std;

int n, dis=0, k=1;
bool visited[maxn];
vector<vector<int>> adj;

void DFS(int u, int kc){
    if (kc>dis){
        dis=kc;
        k=u;
    }
    visited[u]=true;
    for (int v:adj[u]){
        if (visited[v]==false)
            DFS(v, kc+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n; adj.resize(n+1);
    for (int i=1; i<n; i++){
        int u, v; cin>> u>> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1, 0);
    memset(visited, false, sizeof visited);
    DFS(k, 0);
    cout<< dis;
    return 0;
}
