#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, d[1005], inq[1005], cnt[1005], check[1005], E[1005];
vector<ii> adj[1005];

void DFS(int u){
    check[u]=1;
    for (ii p:adj[u]){
        if (check[p.fi]==0) DFS(p.fi);
    }
}

void BellmanFord(){
    fill(d+1, d+n+1, 2e9);
    queue<int> q;
    d[1]=0;
    q.push(1);
    inq[1]=1;
    while (!q.empty()){
        int u=q.front();
        q.pop();
        inq[u]=0;
        for (ii p:adj[u]){
            int v=p.fi, w=p.se;
            if (d[v]>d[u]+w && 100-(d[u]+w)>0){
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
    while (cin>> n){
        if (n==-1) return 0;
        vector<ii> Edge;
        for (int u=1; u<=n; u++){
            int w, c; cin>> w>> c;
            E[u]=w;
            for (int i=1; i<=c; i++){
                int v; cin>> v;
                Edge.push_back({u, v});
            }
        }
        for (ii p:Edge) adj[p.fi].push_back({p.se, -E[p.se]});
        BellmanFord();
        //cout<< -d[n]<< "\n";
        if (100-d[n]>0 || check[n]==1) cout<< "winnable"<< "\n";
        else cout<< "hopeless"<< "\n";
        for (int i=1; i<=n; i++) adj[i].clear();
        memset(d, 0, sizeof d);
        memset(inq, 0, sizeof inq);
        memset(cnt, 0, sizeof cnt);
        memset(check, 0, sizeof check);
        memset(E, 0, sizeof E);
    }
    return 0;
}
