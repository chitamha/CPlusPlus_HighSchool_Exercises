#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define llll pair<ll, ll>
using namespace std;

ll n, m, s, f, d[50005], before[50005], inpq[50005], disst, disnd;
set<llll> adj[50005];
map<llll, ll> visited;

void Erase(ll u, ll v){
    adj[u].erase(adj[u].lower_bound(make_pair(v, -1e18)));
}

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
    for (ll en=f; before[en]!=en; en=before[en]){
        visited[{en, before[en]}]++;
        visited[{before[en], en}]++;
        Erase(en, before[en]);
        auto it=adj[before[en]].lower_bound(make_pair(en, 0));
        ll tmp=(*it).se;
        Erase(before[en], en);
        adj[before[en]].insert({en, -tmp});
        //HIWAY2
        //Thay -tmp thành 1e18 thì WA 2 Test
        //Xóa cạnh (xóa cả hai chiều) thì WA 2 Test
        //Thay đổi [u; v]=1e18 và [v; u]=1e18 thì WA 2 Test
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
    for (ll en=s; before[en]!=en; en=before[en]){
        visited[{en, before[en]}]++;
        visited[{before[en], en}]++;
        Erase(before[en], en);
    }
}

void TruyVet(ll u, vector<ll> Trace){
    Trace.push_back(u);
    if (u==f){
        cout<< Trace.size()<< " ";
        for (ll x:Trace) cout<< x<< " ";
        cout<< endl;
        return;
    }
    else{
        for (pair<ll,ll> p:adj[u]){
            ll v=p.fi;
            if (visited[{u, v}]==1 && visited[{v, u}]==1) TruyVet(v, Trace);
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
    BellmanFord(f);
    //Dijkstra(f); TLE, Chu trinh am?
    if (before[s]==0) return cout<< -1, 0;
    disnd=d[s];
    cout<< disst+disnd<< endl;
    vector<ll> Trace;
    TruyVet(s, Trace);
    return 0;
}
