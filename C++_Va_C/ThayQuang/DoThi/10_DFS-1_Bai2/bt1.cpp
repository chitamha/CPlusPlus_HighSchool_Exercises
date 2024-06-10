#include <bits/stdc++.h>
using namespace std;

int n, m, S, F;
vector<int> adj[1005];
bool visited[1005];
int parent[1005];

void DFS(int u){
    cout<< u<< ", ";
    visited[u]=true;
    for (int i:adj[u]){
        if (!visited[i]){
            parent[i]=u;
            DFS(i);
        }
    }
}

int main(){
    freopen("GRAPH.INP", "r", stdin);
    freopen("GRAPH.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>> n>> m>> S>> F;
    for (int i=1; i<=m; i++){
        int u, v;
        cin>> u>> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(S);
    cout<< endl;
    while (F!=S){
        cout<< F<< " <- ";
        F=parent[F];
    }
    cout<< S;
    return 0;
}
