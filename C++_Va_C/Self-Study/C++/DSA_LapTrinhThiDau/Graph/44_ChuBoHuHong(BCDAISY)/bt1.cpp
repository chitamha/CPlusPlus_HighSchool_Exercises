#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[255];
vector<bool> visited(255, false);

void DFS(int i){
    visited[i]=true;
    for (int j:adj[i])
        if(!visited[j])
            DFS(j);
}

int main()
{
    cin>> n>> m;
    for (int i=1; i<=m; i++)
    {
        int u, v;
        cin>> u>> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1);
    for (int i=1; i<=n; ++i)
        if (!visited[i])
            cout<<i << endl;
    return 0;
}
