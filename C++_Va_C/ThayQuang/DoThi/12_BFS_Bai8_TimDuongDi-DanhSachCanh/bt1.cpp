#include <bits/stdc++.h>
#define maxn 1000006
using namespace std;

int n, m, s, t;
vector<int> adj[maxn];
vector<int> path;
vector<int> parent(maxn);
bool visited[maxn];

void BFS(int u){
    queue<int> q;
    q.push(u);
    visited[u]=true;
    while (!q.empty()){
        int f=q.front();
        q.pop();
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
    freopen("GRAPH8.INP", "r", stdin);
    freopen("GRAPH8.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>> n>> m>> s>> t;
    for (int i=1; i<=m; i++){
        int u, v;
        cin>> u>> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(visited, false, sizeof visited);
    BFS(s);
    if (visited[t]){
        int tmp=t;
        while (s!=t){
            path.push_back(t);
            t=parent[t];
        }
        path.push_back(s);
        cout<< path.size()<< endl;
        for (auto it=path.rbegin(); it!=path.rend(); it++)
            cout<< *it<< " ";
    } else cout<< -1;
    return 0;
}
