#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 30006
using namespace std;

ll n, m;
ll d[3][maxn], Cach[3][maxn];
//1: 1 -> u; 2: n -> u
vector<pair<ll, ll>> adj[maxn];

void dijkstra(ll i, ll t){
    priority_queue<llll, vector<llll>, greater<llll>> pq;
    d[t][i]=0;
    pq.push({0, i});
    while (!pq.empty()){
        ll u=pq.top().se;
        ll kc=pq.top().fi;
        pq.pop();
        if (kc>d[t][u]) continue;
        for (auto p:adj[u]){
            ll v=p.fi, w=p.se;
            if (d[t][v]>d[t][u]+w){
                d[t][v]=d[t][u]+w;
                Cach[t][v]=Cach[t][u];
                pq.push({d[t][v], v});
            } else if (d[t][v]==d[t][u]+w) Cach[t][v]+=Cach[t][u];
        }

    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m;
    for (ll i=1; i<=m; i++){
        ll u, v, w; cin>> u>> v>> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    Cach[1][1]=Cach[2][n]=1;
    memset(d, 62, sizeof d);
    dijkstra(1, 1);
    dijkstra(n, 2);
    queue<ll> q;
    for (ll j=2; j<=n-1; j++){
        if (Cach[1][j]*Cach[2][j]==Cach[1][n] && d[1][j]+d[2][j]==d[1][n]) continue;
        q.push(j);
    }
    cout<< q.size()<< endl;
    while (!q.empty()){
        cout<< q.front()<< endl;
        q.pop();
    }
    return 0;
}
