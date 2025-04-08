#include <bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
#define fi first
#define se second
using namespace std;

ll n, m, d[2505], inq[2505], cnt[2505], parent[2505];
vector<ii> adj[2505];

void BellmanFord(){
    ll Cy=-1;
    queue<ll> q;
    for (int i=1; i<=n; i++){
        parent[i]=i;
        q.push(i);
        inq[i]=1;
    }
    while (!q.empty()){
        ll u=q.front();
        q.pop();
        inq[u]=0;
        for (ii p:adj[u]){
            ll v=p.fi, w=p.se;
            if (d[v]>d[u]+w){
                d[v]=d[u]+w;
                parent[v]=u;
                cnt[v]++;
                if (cnt[v]>n) Cy=v;
                else if (inq[v]==0 && cnt[v]<=n){
                    q.push(v);
                    inq[v]=1;
                }
            }
        }
    }
    if (Cy==-1){
        cout<< "NO";
        return;
    }
    for (ll i=1; i<=n; i++) Cy=parent[Cy];
    cout<< "YES"<< endl;
    vector<ll> Cycle;
    Cycle.push_back(Cy);
    for (int tmp=parent[Cy]; tmp!=Cy; tmp=parent[tmp]) Cycle.push_back(tmp);
    Cycle.push_back(Cy);
    reverse(Cycle.begin(), Cycle.end());
    for (int x:Cycle) cout<< x<< " ";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m;
    for (ll i=1; i<=m; i++){
        ll u, v, w; cin>> u>> v>> w;
        adj[u].push_back({v, w});
    }
    BellmanFord();
    return 0;
}
