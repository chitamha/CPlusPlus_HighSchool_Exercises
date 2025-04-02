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

/*
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<int>> dsk;

// BFS tìm đường đi từ s đến t
// Trả về danh sách các đỉnh trên đường đi
vector<int> find_path(int s, int t, const dsk &ke) {
    int n = ke.size();
    vector<int> trace(n, -1);
    queue<int> q;
    q.push(s);
    trace[s] = s;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: ke[u]) if (trace[v] < 0) {
            q.push(v);
            trace[v] = u;
        }
    }

    vector<int> path;
    int u = t;
    while (u != s) {
        path.push_back(u);
        u = trace[u];
    }
    path.push_back(s);
    for (int i=0, j=path.size()-1; i<j; i++, j--) swap(path[i], path[j]);
    return path;
}

int bfs(int s, const vector<int> &pos, const dsk &ke, vector<bool> &visited) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    int r = pos[s];
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: ke[u]){
            if (!visited[v] && pos[v]<0) {
                q.push(v);
                visited[v] = true;
            }
            r=max(r, pos[v]);
        }
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--, t--;
    dsk ke(n);
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        ke[u-1].push_back(v-1);
    }

    vector<int> path = find_path(s, t, ke);

    // Lưu lại vị trí của đỉnh trên đường đi
    vector<int> pos(n, -1);
    for (int i=0; i<(int)path.size(); i++) {
        pos[path[i]] = i;
    }

    vector<bool> visited(n, false);
    int r = -1, res = 0;
    for (int i=1; i<(int)path.size()-1; i++) {
        // Nếu từ các đỉnh trước u có thể đi tới một
        // đỉnh sau u thì u không xung yếu, ngược lại
        // u là nút xung yếu.
        //for (int j=0; j<n; j++) visited[j]=false;
        r=max(r, bfs(path[i-1], pos, ke, visited));
        if (r <= pos[path[i]]) res++;
    }
    cout << res;
    return 0;
}

*/
