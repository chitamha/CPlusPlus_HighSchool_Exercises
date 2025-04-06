#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define llll pair<ll, ll>
using namespace std;

ll n, m, s, f, d[50005], before[50005], inpq[50005], disst, disnd;
set<llll> adj[50005];

void Dijkstra(ll x){
    memset(d, 62, sizeof d);
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
            if (d[v]>d[u]+w){
                d[v]=d[u]+w;
                pq.push({d[v], v});
                before[v]=u;
            }
        }
    }
}

void BellmanFord(ll x){
    memset(d, 62, sizeof d);
    memset(before, 0, sizeof before);
    priority_queue<llll, vector<llll>, greater<llll>> pq;
    before[x]=x;
    d[x]=0;
    pq.push({0, x});
    inpq[x]=1;
    while (!pq.empty()){
        ll u=pq.top().se;
        pq.pop();
        inpq[u]=0;
        for (llll p:adj[u]){
            ll v=p.fi, w=p.se;
            if (d[v]>d[u]+w){
                before[v]=u;
                d[v]=d[u]+w;
                if (inpq[v]==0){
                    pq.push({d[v], v});
                    inpq[v]=1;
                }
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
        adj[u].insert({v, w});
        adj[v].insert({u, w});
    }
    Dijkstra(s);
    if (before[f]==0) return cout<< -1, 0;
    disst=d[f];
    vector<ll> Trace, SecondTrace;
    ll en=f;
    Trace.push_back(en);
    while (en!=s){
        adj[en].erase(adj[en].lower_bound(make_pair(before[en], 0)));
        auto it=adj[before[en]].lower_bound(make_pair(en, 0));
        int tmp=(*it).se;
        adj[before[en]].erase(adj[before[en]].lower_bound(make_pair(en, 0)));
        adj[before[en]].insert({en, -tmp});
        en=before[en];
        Trace.push_back(en);
    }
    reverse(Trace.begin(), Trace.end());
    BellmanFord(f);
    //Dijkstra(f); TLE, Chu trinh am?
    if (before[s]==0) return cout<< -1, 0;
    disnd=d[s];
    en=s;
    SecondTrace.push_back(en);
    while (en!=f){
        en=before[en];
        SecondTrace.push_back(en);
    }
    cout<< disst+disnd<< endl;
    cout<< Trace.size()<< " ";
    for (ll x:Trace) cout<< x<< " ";
    cout<< endl;
    cout<< SecondTrace.size()<< " ";
    for (ll x:SecondTrace) cout<< x<< " ";
    return 0;
}
