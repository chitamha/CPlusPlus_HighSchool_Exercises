#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1005];
bool visited[1005];
vector<pair<int, int>> canhKe;

void DFS(int i, int u, int v){
    visited[i]=true;
    for (int x:adj[i]){
        if ((x==u && i==v) || (x==v && i==u))
            continue;
        if (!visited[x]){
            DFS(x, u, v);
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
            DFS(i, 0, 0);
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
                DFS(j, x, y);
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
