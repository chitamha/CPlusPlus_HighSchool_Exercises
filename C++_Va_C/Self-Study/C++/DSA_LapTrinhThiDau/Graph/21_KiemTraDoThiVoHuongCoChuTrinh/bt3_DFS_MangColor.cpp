#include <bits/stdc++.h>
#define maxn 1000006
using namespace std;
using ll=long long;

ll n, m, st, en;
vector<ll> adj[maxn];
vector<ll> path;
vector<ll> color(maxn, 0);
vector<ll> parent(maxn);

bool DFS(ll u){
    color[u]=1;
    for (ll v:adj[u]){
        if (color[v]==0){
            parent[v]=u;
            if (DFS(v))
                return true;
        }
        else if (color[v]==1 && v!=parent[u]){
            st=v;
            en=u;
            return true;
        }
    }
    color[u]=2;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>> n>> m;
    for (int i=1; i<=m; i++){
        int u, v;
        cin>> u>> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool check=false;
    for (int i=1; i<=n; i++){
        if (color[i]==0){
            if (DFS(i)){
                check=true;
                break;
            }
        }
    }
    if (check){
        path.push_back(st);
        while (en!=st){
            path.push_back(en);
            en=parent[en];
        }
        path.push_back(en);
        reverse(path.begin(), path.end());
        cout<< path.size()<< endl;
        for (int i:path) cout<< i<< " ";
    } else cout<< "IMPOSSIBLE";
    return 0;
}
