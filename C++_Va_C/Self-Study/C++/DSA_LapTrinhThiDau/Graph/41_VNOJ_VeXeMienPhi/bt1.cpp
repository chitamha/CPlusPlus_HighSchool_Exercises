#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

int n, m, k, s, t;
ll d[100005][10];
vector<pair<int, int>> adj[100005];
struct mt{
    int u, i; ll dis;
    friend bool operator < (mt a, mt b){
        return a.dis>b.dis;
    }
};

void dijkstra(){
    for (int i=1; i<=n; i++){
        for (int j=0; j<=k; j++){
            d[i][j]=1e18;
        }
    }
    priority_queue<mt> pq;
    for (int j=0; j<=k; j++) d[s][j]=0;
    pq.push({s, 0, 0});
    while (!pq.empty()){
        int u=pq.top().u, i=pq.top().i;
        ll kc=pq.top().dis;
        pq.pop();
        if (kc>d[u][i]) continue;
        for (auto p:adj[u]){
            int v=p.fi, w=p.se;
            if (d[v][i]>d[u][i]+w){
                d[v][i]=d[u][i]+w;
                pq.push({v, i, d[v][i]});
            }
            if (i<k){
                if (d[v][i+1]>d[u][i]){
                    d[v][i+1]=d[u][i];
                    pq.push({v, i+1, d[v][i+1]});
                }
            }
        }
    }
}

int main(){
    cin>> n>> m>> k>> s>> t;
    for (int i=1; i<=m; i++){
        int u, v, w;
        cin>> u>> v>> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dijkstra();
    ll ans=1e18;
    for (int i=0; i<=k; i++) ans=min(ans, d[t][i]);
    cout<< ans;
    return 0;
}
