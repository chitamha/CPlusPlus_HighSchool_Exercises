#include <bits/stdc++.h>
#define maxn 1000006
#define inf 1e9+10
#define ll long long
#define fi first
#define se second
#define lli pair<ll, int>
using namespace std;

int n, m, k, A, B;
vector<pair<int, int>> adj[5005], DTien;
ll ans=1e18, d[5005], dA[5005], dB[5005];

void dijkstra(int i){
    priority_queue<lli, vector<lli>, greater<lli>> pq;
    d[i]=0;
    pq.push({0, i});
    while (!pq.empty()){
        int u=pq.top().se;
        ll kc=pq.top().fi;
        pq.pop();
        if (kc>d[u]) continue;
        for (auto p:adj[u]){
            int v=p.fi, w=p.se;
            if (d[v]>d[u]+1ll*w){
                d[v]=d[u]+1ll*w;
                pq.push({d[v], v});
            }
        }
    }
}

int main(){
    freopen("TIENCO.INP", "r", stdin);
    freopen("TIENCO.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m>> k>> A>> B;
    for (int i=1; i<=k; i++){
        int vitri, cost;
        cin>> vitri>> cost;
        DTien.push_back({vitri, cost});
    }
    for (int i=1; i<=m; i++){
        int u, v, w;
        cin>> u>> v>> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    memset(d, 62, sizeof d);
    dijkstra(A);
    for (int i=1; i<=n; i++) dA[i]=d[i];
    memset(d, 62, sizeof d);
    dijkstra(B);
    for (int i=1; i<=n; i++) dB[i]=d[i];
    for (auto it:DTien){
        ans=min(ans, dA[it.fi]+dB[it.fi]+1ll*it.se);
    }
    cout<< ans;
    return 0;
}
