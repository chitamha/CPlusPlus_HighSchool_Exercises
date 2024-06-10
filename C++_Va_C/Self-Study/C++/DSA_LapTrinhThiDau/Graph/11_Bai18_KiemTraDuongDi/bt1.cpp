#include <bits/stdc++.h>
using namespace std;

int n, m, q, dem=0;
vector<vector<int>> adj;
vector<bool> visited(n+1, false);
vector<int> ID(n+1, 0);

void reset(){
    for (int i=1; i<=n; i++){
        visited[i]=false;
        ID[i]=0;
    }
}
void DFS(int i){
    cout<< i<< " ";
    visited[i]=true;
    ID[i]=dem;
    for (int x:adj[i]){
        if (!visited[x]){
            DFS(x);
        }
    }
}

void BFS(int i){
    queue<int> q;
    q.push(i);
    visited[i]=true;
    while (!q.empty()){
        int x=q.front();
        cout<< x<< " ";
        ID[x]=dem;
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
    adj.resize(n+1);
    for (int i=1; i<=m; i++){
        int u, v;
        cin>> u>> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i=1; i<=n; i++){
        sort(adj[i].begin(), adj[i].end());
    }
    for (int i=1; i<=n; i++){
        if (!visited[i]){
            dem++;
            DFS(i);
        }
    }
    cout<< endl;
    cout<< "visited"<< endl;
    for (int i=1; i<=n; i++){
        cout<< visited[i]<< " ";
    }
    cout<< endl<< "ID"<< endl;
    for (int i=1; i<=n; i++){
        cout<< ID[i]<< " ";
    }
    cout<< endl;
    reset();
    dem=0;
    cout<< "Sau khi reset"<< endl;
    cout<< "visited"<< endl;
    for (int i=1; i<=n; i++){
        cout<< visited[i]<< " ";
    }
    cout<< endl<< "ID"<< endl;
    for (int i=1; i<=n; i++){
        cout<< ID[i]<< " ";
    }
    cout<< endl;
    for (int i=1; i<=n; i++){
        if (!visited[i]){
            dem++;
            BFS(i);
        }
    }
    cout<< endl;
    cout<< "visited"<< endl;
    for (int i=1; i<=n; i++){
        cout<< visited[i]<< " ";
    }
    cout<< endl<< "ID"<< endl;
    for (int i=1; i<=n; i++){
        cout<< ID[i]<< " ";
    }
    cout<< endl;
    cin>> q;
    for (int i=1; i<=q; i++){
        int x, y;
        cin>> x>> y;
        if (ID[x]==ID[y])
            cout<< 1<< endl;
        else cout<< -1<< endl;
    }
    return 0;
}
