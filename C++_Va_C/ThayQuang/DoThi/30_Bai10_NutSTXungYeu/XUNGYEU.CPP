#include <bits/stdc++.h>
using namespace std;

int n, m, s, t, visited[10005], before[10005], ans=0;
vector<int> adj[10005];

int DFS(int u, int Rm){
    visited[u]=1;
    if (u==t) return 1;
    for (int v:adj[u]){
        if (!visited[v] && v!=Rm){
            before[v]=u;
            if (DFS(v, Rm)) return 1;
        }
    }
    return 0;
}

int main(){
    freopen("XungYeu.INP", "r", stdin);
    freopen("XungYeu.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m>> s>> t;
    for (int i=1; i<=m; i++){
        int u, v; cin>> u>> v;
        adj[u].push_back(v);
    }
    DFS(s, 0);
    vector<int> Vet;
    int tmp=t;
    while (before[tmp]!=s){
        Vet.push_back(before[tmp]);
        //cout<< before[tmp]<< " ";
        tmp=before[tmp];
    }
    //cout<< endl;
    for (int x:Vet){
        memset(visited, 0, sizeof visited);
        DFS(s, x);
        if (visited[t]==0) ans++;
    }
    cout<< ans;
    return 0;
}
