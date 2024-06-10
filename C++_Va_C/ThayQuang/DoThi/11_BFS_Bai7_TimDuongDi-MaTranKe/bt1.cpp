#include <bits/stdc++.h>
using namespace std;

int n, s, t;
int A[1005][1005];
vector<int> path;
vector<int> parent(1005);
bool visited[1005];

void BFS(int u){
    queue<int> q;
    q.push(u);
    visited[u]=true;
    while (!q.empty()){
        int f=q.front();
        q.pop();
        for (int v=1; v<=n; v++){
            if (A[f][v] && !visited[v]){
                q.push(v);
                visited[v]=true;
                parent[v]=f;
            }
        }
    }
}

int main(){
    freopen("GRAPH7.INP", "r", stdin);
    freopen("GRAPH7.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>> n>> s>> t;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin>> A[i][j];
        }
    }
    memset(visited, false, sizeof visited);
    BFS(s);
    if (visited[t]){
        while (s!=t){
            path.push_back(t);
            t=parent[t];
        }
        path.push_back(s);
        cout<< path.size()<< endl;
        for (auto it=path.rbegin(); it!=path.rend(); it++)
            cout<< *it<< " ";
    } else cout<< -1;
    return 0;
}
