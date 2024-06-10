#include <bits/stdc++.h>
using namespace std;

int n, m, cnt;
vector<int> adj[1005];
vector<bool> visited(1005, false);

void BFS(int i){
    queue<int> q;
    q.push(i);
    visited[i]=true;
    while (!q.empty()){
        int x=q.front();
        q.pop();
        for (int y:adj[x]){
            if (!visited[y]){
                q.push(y);
                visited[y]=true;
            }
        }
    }
}

int main(){
    cin>> n>> m;
    for (int i=1; i<=m; i++){
        int u, v; cin>> u>> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i=1; i<=n; i++){
        sort(adj[i].begin(), adj[i].end());
    }
    for (int i=1; i<=n; i++){
        if (!visited[i]){
            cnt++;
            BFS(i);
        }
    }
    vector<int> path;
    int sotplt=0;
    for (int i=1; i<=n; i++){
        visited.assign(visited.size(), false);
        int tam=0;
        visited[i]=true;
        for (int j=1; j<=n; j++){
            if (!visited[j]){
                tam++;
                BFS(j);
            }
        }
        if (tam>cnt){
            path.push_back(i);
            sotplt++;
        }
    }
    cout<< sotplt<< endl;
    for (int x:path) cout<< x<< ' ';
    return 0;
}
