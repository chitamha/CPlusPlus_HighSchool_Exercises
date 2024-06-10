#include <bits/stdc++.h>
using namespace std;

int n, m, S, F;
vector<int> adj[1005];
bool visited[1005];
int parent[1005];
vector<int> path;

void BFS(int u){
    queue<int> q;
    q.push(u);
    visited[u]=true;
    while (!q.empty()){
        int f=q.front();
        q.pop();
        cout<< f<< ", ";
        for (int v:adj[f]){
            if (!visited[v]){
                q.push(v);
                visited[v]=true;
                parent[v]=f;
            }
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
    BFS(S);
    cout<< endl;
    while (F!=S){
        path.push_back(F);
        F=parent[F];
    }
    path.push_back(S);
    reverse(path.begin(), path.end());
    for (int i:path){
        cout<< i;
        if (i!=*(path.rbegin())){
            cout<< " -> ";
        }
    }
    return 0;
}
