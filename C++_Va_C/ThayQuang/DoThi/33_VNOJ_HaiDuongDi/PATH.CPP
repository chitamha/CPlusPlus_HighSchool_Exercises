#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define llll pair<ll, ll>
using namespace std;

ll n, m, s, f, d[105], before[105], disst, disnd=1e18;
vector<llll> adj[105];

void Dijkstra(ll x, ll a, ll b){
    priority_queue<llll, vector<llll>, greater<llll>> pq;
    d[x]=0;
    pq.push({0, x});
    before[x]=x;
    while (!pq.empty()){
        ll u=pq.top().se, dis=pq.top().fi;
        pq.pop();
        if (dis>d[u]) continue;
        for (llll p:adj[u]){
            ll v=p.fi, w=p.se;
            if ((u==a && v==b) || (u==b && v==a)) continue;
            if (d[v]>d[u]+w){
                d[v]=d[u]+w;
                pq.push({d[v], v});
                before[v]=u;
            }
        }
    }
}

int main(){
    freopen("PATH.INP", "r", stdin);
    freopen("PATH.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m>> s>> f;
    for (ll i=1; i<=m; i++){
        ll u, v, w; cin>> u>> v>> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    memset(d, 62, sizeof d);
    Dijkstra(s, 0, 0);
    if (before[f]==0) return cout<< -1, 0;
    disst=d[f];
    vector<ll> Trace, SecondTrace;
    ll en=f;
    while (before[en]!=en){
        Trace.push_back(en);
        en=before[en];
    }
    Trace.push_back(en);
    reverse(Trace.begin(), Trace.end());
    for (ll i=0; i<Trace.size()-1; i++){
        memset(d, 62, sizeof d);
        memset(before, 0, sizeof before);
        Dijkstra(s, Trace[i], Trace[i+1]);
        if (d[f]<disnd){
            disnd=d[f];
            en=f;
            while (before[en]!=en){
                SecondTrace.push_back(en);
                en=before[en];
            }
        }
    }
    if (before[f]==0) return cout<< -1, 0;
    SecondTrace.push_back(en);
    reverse(SecondTrace.begin(), SecondTrace.end());
    cout<< disst+disnd<< endl;
    cout<< Trace.size()<< " ";
    for (ll x:Trace) cout<< x<< " ";
    cout<< endl;
    cout<< SecondTrace.size()<< " ";
    for (ll x:SecondTrace) cout<< x<< " ";
    return 0;
}
