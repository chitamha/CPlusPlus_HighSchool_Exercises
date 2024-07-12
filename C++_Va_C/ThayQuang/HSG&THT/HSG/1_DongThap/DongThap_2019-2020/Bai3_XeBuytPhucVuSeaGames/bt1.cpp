#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define maxn 100006
using namespace std;

ll n, a, b;
vector<ll> adj[maxn];
ll d[maxn], visited[maxn];

void bfs(ll i){
    queue<ll> q;
    q.push(i);
    d[i]=0;
    while (!q.empty()){
        ll u=q.front(); q.pop();
        if (visited[u]) continue;
        visited[u]=1;
        for (ll v:adj[u]){
            if (visited[v]) continue;
            d[v]=min(d[u]+1, d[v]);
            q.push(v);
        }
    }
}

int main(){
    freopen("XEBUYT.INP", "r", stdin);
    freopen("XEBUYT.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> a>> b;
    for (ll i=1; i<=n; i++){
        ll u, v; cin>> u>> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(d, 62, sizeof d);
    bfs(a);
    if (visited[b]) cout<< d[b]-1;
    else cout<< -1;
    return 0;
}
