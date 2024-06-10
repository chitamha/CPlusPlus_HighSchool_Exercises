#include <bits/stdc++.h>
using namespace std;

int n, m, s, t;
vector<int> adj[1005];
vector<bool> visited(1005, false);
vector<int> parent(1005);
vector<int> path;


void BFS(int i){
    queue<int> q;
    q.push(i);
    visited[i]=true;
    while (!q.empty()){
        int x=q.front();
        q.pop();
        for (int y:adj[x]){
            if (!visited[y]){
                parent[y]=x;
                q.push(y);
                visited[y]=true;
            }
        }
    }
}

int main(){
    cin>> n>> m>> s>> t;
    for (int i=1; i<=m; i++){
        int u, v; cin>> u>> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i=1; i<=n; i++){
        sort(adj[i].begin(), adj[i].end());
    }
    BFS(s);
    if (visited[t]){
        while (t!=s){
            path.push_back(t);
            t=parent[t];
        }
        path.push_back(s);
    } else{
        cout<< -1;
        return 0;
    }
    reverse(path.begin(), path.end());
    for (int x:path) cout<< x<< " ";
    return 0;
}
