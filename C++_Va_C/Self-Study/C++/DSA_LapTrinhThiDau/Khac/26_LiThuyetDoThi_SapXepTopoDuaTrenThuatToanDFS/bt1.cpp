#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1005];
bool color[1005];
vector<int> topo;

void DFS(int u){
    color[u]=1;
    for (int v:adj[u]){
        if (color[v]==0) DFS(v);
    }
    color[u]=2;
    topo.push_back(u);
}

int main(){
    cin>> n>> m;
    for (int i=1; i<=m; i++){
        int u, v;
        cin>> u>> v;
        adj[u].push_back(v);
    }
    for (int i=1; i<=n; i++){
        if (color[i]==0){
            DFS(i);
        }
    }
    reverse(topo.begin(), topo.end());
    for (auto i:topo) cout<< i<< " ";
    return 0;
}
