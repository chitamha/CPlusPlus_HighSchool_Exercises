#include <bits/stdc++.h>
using namespace std;

int n, m, s;
vector<int> adj[1005];
vector<bool> visited(1005, false);

void BFS(int i){
    queue<int> q;
    cout<< i<< ' ';
    q.push(i);
    while (!q.empty()){
        int x=q.front();
        q.pop();
        visited[i]=true;
        for (int y:adj[x]){
            if (!visited[y]){
                cout<< y<< ' ';
                q.push(y);
                visited[y]=true;
            }
        }
    }
}

int main(){
    cin>> n>> m>> s;
    for (int i=1; i<=m; i++){
        int u, v; cin>> u>> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i=1; i<=n; i++){
        sort(adj[i].begin(), adj[i].end());
    }
    BFS(s);
    return 0;
}
