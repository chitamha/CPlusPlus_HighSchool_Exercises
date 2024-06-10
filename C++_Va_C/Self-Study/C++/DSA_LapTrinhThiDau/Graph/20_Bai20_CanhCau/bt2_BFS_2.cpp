#include <bits/stdc++.h>
using namespace std;

int n, m;
set<int> adj[1005];
bool visited[1005];
vector<pair<int, int>> canhKe;

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
        int u, v;
        cin>> u>> v;
        adj[u].insert(v);
        adj[v].insert(u);
        canhKe.push_back({u, v});
    }
    int cntpast=0;
    for (int i=1; i<=n; i++){
        if (!visited[i]){
            cntpast++;
            BFS(i);
        }
    }
    int cnttplt=0;
    vector<pair<int, int>> path;
    for (auto i:canhKe){
        memset(visited, false, sizeof visited);
        int cnt=0;
        int x=i.first, y=i.second;
        adj[x].erase(y);
        adj[y].erase(x);
        for (int j=1; j<=n; j++){
            if (!visited[j]){
                cnt++;
                BFS(j);
            }
        }
        if (cnt>cntpast){
            cnttplt++;
            path.push_back({i.first, i.second});
        }
        adj[x].insert(y);
        adj[y].insert(x);
    }
    cout<< cnttplt<< endl;
    for (auto i:path) cout<< i.first<< " "<< i.second<< endl;
    return 0;
}
