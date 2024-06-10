#include <bits/stdc++.h>
using namespace std;

bool check=false;
set<int> adj[1005];
vector<bool> visited(1005);
int parent[1005];

void DFS1(int u){
    visited[u]=true;
    for (int v:adj[u]){
        if (!visited[v]){
            parent[v]=u;
            DFS1(v);
        } else{
            if (v!=parent[u])
                check=true;
        }
    }
}

bool DFS2(int u){
    visited[u]=true;
    for (int v:adj[u]){
        if (!visited[v]){
            parent[v]=u;
            if (DFS2(v))
                return true;
        } else{
            if (v!=parent[u])
                return true;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin>> n>> m;
    for (int i=1; i<=m; i++){
        int u, v;
        cin>> u>> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    DFS1(1);
    if (check) cout<< "Do thi CO chu trinh\n";
    else cout<< "Do thi KHONG CO chu trinh\n";
    visited.assign(visited.size(), false);
    if (DFS2(1)) cout<< "Do thi CO chu trinh\n";
    else cout<< "Do thi KHONG CO chu trinh\n";
    return 0;
}
