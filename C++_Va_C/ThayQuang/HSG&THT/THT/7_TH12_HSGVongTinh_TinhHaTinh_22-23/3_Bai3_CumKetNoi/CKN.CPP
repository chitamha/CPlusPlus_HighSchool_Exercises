#include <bits/stdc++.h>
#define maxn 20006
using namespace std;

int n, m, id[maxn], child[maxn], isjoint[maxn], low[maxn], cnt=0, tpltbd=0;
vector<int> adj[maxn];

void dfs(int u, int p){
    id[u]=low[u]=++cnt;
    int node=(p!=0);
    for (int v:adj[u]){
        if (v==p) continue;
        if (id[v]) low[u]=min(low[u], id[v]);
        else{
            dfs(v, u);
            low[u]=min(low[u], low[v]);
            child[u]++;
            if (low[v]>=id[u]) node++;
        }
    }
    if (node>=2) isjoint[u]=1;
}

int main(){
    //freopen("CKN.INP", "r", stdin);
    //freopen("CKN.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m;
    for (int i=1; i<=m; i++){
        int u, v;
        cin>> u>> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i=1; i<=n; i++){
        if (id[i]==0){
            dfs(i, 0);
            tpltbd++;
        }
    }
    /*
    cout<< "Khop: ";
    for (int i=1; i<=n; i++) if (isjoint[i]) cout<< i<< " ";
    cout<< endl;
    cout<< "Tpltbd: "<< tpltbd<< endl;
    */
    for (int i=1; i<=n; i++){
        if (isjoint[i]) cout<< tpltbd+child[i]<< "\n";
        else cout<< tpltbd<< "\n";
    }
    return 0;
}
