#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1005];
bool visited[1005];
vector<pair<int, int>> canhKe;

void BFS(int i, int u, int v){
    queue<int> q;
    q.push(i);
    visited[i]=true;
    while (!q.empty()){
        int x=q.front();
        q.pop();
        for (int y:adj[x]){
            if ((x==u && y==v) || (x==v && y==u)){
                continue;
            }
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
        adj[u].push_back(v);
        adj[v].push_back(u);
        canhKe.push_back({u, v});
    }
    int cntpast=0;
    for (int i=1; i<=n; i++){
        if (!visited[i]){
            cntpast++;
            BFS(i, 0, 0);
        }
    }
    int cnttplt=0;
    vector<pair<int, int>> path;
    for (auto i:canhKe){
        memset(visited, false, sizeof visited);
        int cnt=0;
        int x=i.first;
        int y=i.second;
        for (int j=1; j<=n; j++){
            if (!visited[j]){
                cnt++;
                BFS(j, x, y);
            }
        }
        if (cnt>cntpast){
            cnttplt++;
            path.push_back({i.first, i.second});
        }
    }
    cout<< cnttplt<< endl;
    for (auto i:path) cout<< i.first<< " "<< i.second<< endl;
    return 0;
}
