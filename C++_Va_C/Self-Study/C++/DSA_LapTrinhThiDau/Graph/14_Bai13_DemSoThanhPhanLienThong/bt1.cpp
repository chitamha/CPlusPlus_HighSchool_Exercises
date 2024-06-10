#include <bits/stdc++.h>
using namespace std;

int n, m, s, cnt;
vector<int> adj[1005];
vector<bool> visited(1005, false);
vector<int> ID(1005, 0);

void DFS(int i){
    visited[i]=true;
    ID[i]=cnt;
    for (int x:adj[i]){
        if (!visited[x]){
            DFS(x);
        }
    }
}

void BFS(int i){
    queue<int> q;
    q.push(i);
    visited[i]=true;
    ID[i]=cnt;
    while (!q.empty()){
        int x=q.front();
        q.pop();
        for (int y:adj[x]){
            if (!visited[y]){
                q.push(y);
                visited[y]=true;
                ID[y]=cnt;
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
        if (!visited[i]){
            cnt++;
            BFS(i);
        }
    }
    cout<< cnt;
    cout<< endl;
    cnt=0;
    for (int i=0; i<=1004; i++){
        ID[i]=0;
        visited[i]=false;
    }
    for (int i=1; i<=n; i++){
        if (!visited[i]){
            cnt++;
            DFS(i);
        }
    }
    cout<< cnt;
    return 0;
}
