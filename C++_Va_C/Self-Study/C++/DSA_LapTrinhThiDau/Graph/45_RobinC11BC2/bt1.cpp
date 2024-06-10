#include <bits/stdc++.h>
#define maxn 10005
using namespace std;

int n, m;
bool check, gap2;
vector<pair<int, int>> adj[maxn];
vector<bool> visited(maxn, false);

void DFS(int x, int y){
    visited[x]=true;
    for (auto h:adj[x]){
        int h1=h.first;
        int h2=h.second;
        if (h2==2) gap2=true;
        if (h1==y){
            if (gap2)
                check=true;
        }
        visited[h1]=true;
        DFS(h1, y);
    }
}

int main(){
    cin>> n>> m;
    for (int i=2; i<=n; i++){
        int u, k;
        cin>> u>> k;
        adj[i].push_back({u, k});
        adj[u].push_back({i, k});
    }
    for (int i=1; i<=n; i++){
        sort(adj[i].begin(), adj[i].end());
    }
    for (int i=1; i<=m; i++){
        int x, y;
        visited.assign(visited.size(), false);
        check=false;
        gap2=false;
        cin>> x>> y;
        DFS(x, y);
        if (check)
            cout<< "YES\n";
        else
            cout<< "NO\n";
    }
    return 0;
}
