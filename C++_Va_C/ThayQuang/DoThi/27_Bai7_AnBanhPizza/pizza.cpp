#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int n, m, q, hmany, Price[100005], visited[100005];
double Bill[100005];
vector<int> adj[100005];
vector<pair<int, int>> Ate;
set<int> se;

void DFS(int u, int which, int siz){
    if (siz!=0) Bill[u]=1.0*Price[which]/siz;
    //if (siz!=0) cout<< u<< " ";
    hmany++;
    visited[u]=1;
    for (int v:adj[u]){
        if (!visited[v])
            DFS(v, which, siz);
    }
}

int main(){
    freopen("PIZZA.INP", "r", stdin);
    freopen("PIZZA.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m>> q;
    for (int i=1; i<=m; i++) cin>> Price[i];
    for (int i=1; i<=q; i++){
        int typ, x, y;
        cin>> typ>> x>> y;
        if (typ==1) se.insert(y), Ate.push_back({x, y});
        else adj[x].push_back(y), adj[y].push_back(x); {}
    }
    for (pair<int, int> p:Ate){
        hmany=0;
        memset(visited, 0, sizeof visited);
        DFS(p.fi, p.se, 0);
        memset(visited, 0, sizeof visited);
        //cout<< p.se<< ": ";
        DFS(p.fi, p.se, hmany);
        //cout<< "\n";
    }
    cout<< se.size()<< "\n";
    for (int i=1; i<=n; i++) cout<< fixed<< setprecision(8)<< Bill[i]<< "\n";
    return 0;
}
