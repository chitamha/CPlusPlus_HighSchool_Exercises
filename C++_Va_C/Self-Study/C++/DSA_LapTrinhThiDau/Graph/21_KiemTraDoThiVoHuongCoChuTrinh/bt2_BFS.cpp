#include <bits/stdc++.h>
using namespace std;

bool check=false;
set<int> adj[1005];
vector<bool> visited(1005);
int parent[1005];

void BFS1(int u){
    queue<int> q;
    q.push(u);
    visited[u]=true;
    while (!q.empty()){
        int v=q.front();
        q.pop();
        for (int i:adj[v]){
            if (!visited[i]){
                parent[i]=v;
                q.push(i);
                visited[i]=true;
            } else{
                if (i!=parent[v])
                    check=true;
            }
        }
    }
}

bool BFS2(int u){
    queue<int> q;
    q.push(u);
    visited[u]=true;
    while (!q.empty()){
        int v=q.front();
        q.pop();
        for (int i:adj[v]){
            if (!visited[i]){
                parent[i]=v;
                q.push(i);
                visited[i]=true;
            } else{
                if (i!=parent[v])
                    return true;
            }
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
    BFS1(1);
    if (check) cout<< "Do thi CO chu trinh\n";
    else cout<< "Do thi KHONG CO chu trinh\n";
    visited.assign(visited.size(), false);
    if (BFS2(1)) cout<< "Do thi CO chu trinh\n";
    else cout<< "Do thi KHONG CO chu trinh\n";
    return 0;
}
