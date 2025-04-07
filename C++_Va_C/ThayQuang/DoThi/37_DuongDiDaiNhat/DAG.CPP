#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define ill pair<int, ll>
using namespace std;

int n, m, s, t, d[300005], F[300005], before[300005], cnt=0;
vector<ill> adj[300005];
ll MOD=1000000007;

void Dijkstra(){
    memset(d, 62, sizeof d);
    priority_queue<ill, vector<ill>, greater<ill>> pq;
    d[s]=0;
    F[s]=1;
    before[s]=s;
    pq.push({0, s});
    while (!pq.empty()){
        int u=pq.top().se; ll dis=pq.top().fi;
        pq.pop();
        if (dis>d[u]) continue;
        for (pair<int, int> p:adj[u]){
            int v=p.fi, w=p.se;
            if (d[v]>=d[u]+w){
                d[v]=d[u]+w;
                F[v]=(F[v]+F[u])%MOD;
                before[v]=u;
                pq.push({d[v], v});
            }
        }
    }
    for (int en=t; en!=before[en]; en=before[en]) cnt++;
}

int main(){
    freopen("DAG.INP", "r", stdin);
    freopen("DAG.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m>> s>> t;
    for (int i=1; i<=m; i++){
        int a, b, c;
        cin>> a>> b>> c;
        adj[a].push_back({b, -(c+1000)});
    }
    Dijkstra();
    if (F[t]==0) cout<< "NO PATH";
    else cout<< -d[t]-1000*cnt<< endl<< F[t];
    return 0;
}
