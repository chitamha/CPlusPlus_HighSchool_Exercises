#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, m, q, s, d[1005], inq[1005], cnt[1005], check[1005];
vector<ii> adj[1005];

void DFS(int u){
    check[u]=1;
    for (ii p:adj[u]){
        if (check[p.fi]==0) DFS(p.fi);
    }
}

void BellmanFord(){
    fill(d, d+n, 2e9);
    queue<int> q;
    d[s]=0;
    q.push(s);
    inq[s]=1;
    while (!q.empty()){
        int u=q.front();
        q.pop();
        inq[u]=0;
        for (ii p:adj[u]){
            int v=p.fi, w=p.se;
            if (d[v]>d[u]+w){
                d[v]=d[u]+w;
                cnt[v]++;
                if (cnt[v]>n) check[v]=1;
                else if (inq[v]==0 && cnt[v]<=n){
                    q.push(v);
                    inq[v]=1;
                }
            }
        }
    }
    for (int i=1; i<=n; i++){
        if (check[i]) DFS(i);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    while (cin>> n>> m>> q>> s){
        if (n==0 && m==0 && q==0 && s==0) return 0;
        for (int i=1; i<=m; i++){
            int u, v, w; cin>> u>> v>> w;
            adj[u].push_back({v, w});
        }
        BellmanFord();
        while (q--){
            int t; cin>> t;
            if (d[t]==2e9) cout<< "Impossible"<< endl;
            else if (check[t]) cout<< "-Infinity"<< endl;
            else cout<< d[t]<< endl;
        }
        cout<< endl;
        for (int i=0; i<n; i++) adj[i].clear();
        memset(d, 0, sizeof d);
        memset(inq, 0, sizeof inq);
        memset(cnt, 0, sizeof cnt);
        memset(check, 0, sizeof check);
    }
    return 0;
}
