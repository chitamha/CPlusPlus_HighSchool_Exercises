#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int n, m, q, cnt, Price[100005], visited[100005];
vector<int> adj[100005];
map<int, int> mp;

void DFS(int u, int which){
    cnt++;
    visited[u]=which;
    for (int v:adj[u]){
        if (!visited[v])
            DFS(v, which);
    }
}

int main(){
    freopen("PIZZA.INP", "r", stdin);
    freopen("PIZZA.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m>> q;
    for (int i=1; i<=m; i++) cin>> Price[i];
    map<int, int> tmp;
    for (int i=1; i<=q; i++){
        int typ, x, y;
        cin>> typ>> x>> y;
        if (typ==1) tmp[y]=x;
        else adj[x].push_back(y), adj[y].push_back(x); {}
    }
    for (auto p:tmp){
        cnt=0;
        DFS(p.se, p.fi);
        if (mp.count(p.fi)==0) mp[p.fi]=cnt;
    }
    cout<< mp.size()<< "\n";
    for (int i=1; i<=n; i++) cout<< fixed<< setprecision(8)<< 1.0*Price[visited[i]]/mp[visited[i]]<< "\n";
    return 0;
}
