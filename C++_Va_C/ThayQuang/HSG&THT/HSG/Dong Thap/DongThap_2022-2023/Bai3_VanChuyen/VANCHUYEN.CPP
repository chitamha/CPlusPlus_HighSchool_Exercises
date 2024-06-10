#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 100006
using namespace std;

int n, m, s, t;
vector<pair<int, int>> adj[maxn];
ll dis[maxn];

void dijsktra(int u, int kc){
    priority_queue<llll, vector<llll>, greater<llll>> pq;
    dis[u]=0;
    pq.push({0, u});
    while (!pq.empty()){
        auto top=pq.top();
        pq.pop();
        ll kc=top.fi;
        int x=top.se;
        if (kc>dis[x]) continue;
        for (auto p:adj[x]){
            int v=p.fi, w=p.se;
            if (dis[v]>dis[x]+w){
                dis[v]=dis[x]+w;
                pq.push({dis[v], v});
            }
        }

    }

}

int main(){
    freopen("VANCHUYEN.INP", "r", stdin);
    freopen("VANCHUYEN.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    memset(dis, 0x3f3f3f3f3f3f, sizeof dis);
    cin>> n>> m>> s>> t;
    for (int i=1; i<=m; i++){
        int u, v, w;
        cin>> u>> v>> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dijsktra(s, 0);
    cout<< dis[t];
    return 0;
}
