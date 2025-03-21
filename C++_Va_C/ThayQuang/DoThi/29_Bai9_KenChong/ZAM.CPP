#include <bits/stdc++.h>
#define fi first
#define se second
#define ii pair<int, int>
using namespace std;

int n, m, w, k, s, Cost[105];
vector<int> adj[105];

int DFS(int u, vector<int> TruyVet, int sum){
    for (int v:adj[u]){
        if (v==k){
            if (sum+Cost[v]==s){
                TruyVet.push_back(v);
                sum+=Cost[v];
                for (int x:TruyVet) cout<< x<< " ";
                return 1;
            }
            continue;
        }
        if (sum+Cost[v]<s){
            TruyVet.push_back(v);
            sum+=Cost[v];
            if (DFS(v, TruyVet, sum)) return 1;
            TruyVet.pop_back();
            sum-=Cost[v];
        }
    }
    return 0;
}

int main(){
    freopen("ZAM.INP", "r", stdin);
    freopen("ZAM.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m>> w>> k>> s;
    for (int i=1; i<=n; i++) cin>> Cost[i];
    for (int i=1; i<=m; i++){
        int u, v; cin>> u>> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> Vet={w};
    DFS(w, Vet, Cost[w]);
    return 0;
}
