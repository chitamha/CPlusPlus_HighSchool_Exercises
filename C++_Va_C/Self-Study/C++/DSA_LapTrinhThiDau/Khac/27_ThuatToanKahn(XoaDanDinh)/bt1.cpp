#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1005];
int degreein[1005];
bool visited[1005];
//khong can mang visited cung duoc
vector<int> Topo;

void KAHN(){
    queue<int> q;
    for (int i=1; i<=n; i++){
        if (degreein[i]==0){
            q.push(i);
            visited[i]=true;
        }
    }
    while (!q.empty()){
        int u=q.front(); q.pop();
        Topo.push_back(u);
        for (int v:adj[u]){
            degreein[v]--;
            if (!visited[v] && degreein[v]==0){
                q.push(v);
                visited[v]=true;
            }
        }
    }
}

int main(){
    memset(visited, false, sizeof visited);
    memset(degreein, 0, sizeof degreein);
    cin>> n>> m;
    for (int i=1; i<=m; i++){
        int u, v;
        cin>> u>> v;
        adj[u].push_back(v);
        degreein[v]++;
    }
    KAHN();
    for (int i:Topo) cout<< i<< " ";
    return 0;
}
