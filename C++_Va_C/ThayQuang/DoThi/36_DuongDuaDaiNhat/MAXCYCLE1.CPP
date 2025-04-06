#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
using namespace std;

int n, m, color[20005], par[20005], ans=0;
vector<int> adj[20005];
set<pair<int, int>> Se;

void DFS(int u, int p){
    //cout<< u<< endl;
    color[u]=1;
    for (int v:adj[u]){
        if (v==p) continue;
        if (color[v]==0){
            par[v]=u;
            DFS(v, u);
        }
        else if (color[v]==1){
            if (Se.count({u, v})==0 && Se.count({v, u})==0)
                Se.insert({v, u});
        }
    }
    color[u]=2;
}

int main(){
    freopen("MAXCYCLE.INP", "r", stdin);
    freopen("MAXCYCLE.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m;
    for (int i=1; i<=m; i++){
        int u, v; cin>> u>> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i=1; i<=n; i++){
        if (color[i]==0) DFS(i, i);
    }
    //for (int i=1; i<=n; i++) cout<< i<< ": "<< par[i]<< endl;
    for (pair<int, int> p:Se){
        int en=p.se, cnt=1;
        while (en!=p.fi){
            en=par[en];
            cnt++;
            //cout<< en<< " ";
        }
        ans=max(ans, cnt);
    }
    cout<< ans;
    return 0;
}
