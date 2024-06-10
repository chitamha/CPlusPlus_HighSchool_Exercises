#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<int> adj[1005];
bool visited[1005];

void BFS(int u){
    queue<int> q;
    q.push(u);
    visited[u]=true;
    while (!q.empty()){
        int f=q.front();
        q.pop();
        cout<< f<< ' ';
        for (int v:adj[f]){
            if (!visited[v]){
                q.push(v);
                visited[v]=true;
            }
        }
    }
}

int main(){
    freopen("GRAPH.INP", "r", stdin);
    freopen("GRAPH.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>> n>> m>> k;
    for (int i=1; i<=m; i++){
        int u, v;
        cin>> u>> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    BFS(k);
    return 0;
}
