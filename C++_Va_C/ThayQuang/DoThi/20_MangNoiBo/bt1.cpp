#include <bits/stdc++.h>
#define ll long long
#define maxn 1000006
using namespace std;

ll n, m, s, t, sum=0, use[205][205];
vector<pair<ll, ll>> adj[maxn];
vector<ll> d(maxn, 1e9);
vector<ll> parent(maxn);

void dijkstra(ll s){
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> Q;
    Q.push({0, s});
    d[s]=0;
    while (!Q.empty()){
        auto top=Q.top(); Q.pop();
        ll kc=top.first, u=top.second;
        if (kc>d[u]) continue;
        for (auto p:adj[u]){
            ll v=p.first, w=p.second;
            if (use[u][v]==0) continue;
            if (d[v]>d[u]+w){
                parent[v]=u;
                d[v]=d[u]+w;
                Q.push({d[v], v});
            }
        }
    }
}

int main(){
    cin>> n>> m>> s>> t;
    for (ll i=1; i<=m; i++){
        ll u, v, w;
        cin>> u>> v>> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        use[u][v]=use[v][u]=1;
    }
    dijkstra(s);
    sum+=d[t];
    int tmp=t;
    vector<int> path1;
    while (tmp!=s){
        path1.push_back(tmp);
        use[parent[tmp]][tmp]=0;
        use[tmp][parent[tmp]]=0;
        tmp=parent[tmp];
    }
    path1.push_back(s);
    reverse(path1.begin(), path1.end());
    /*
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++) cout<< use[i][j]<< " ";
        cout<< endl;
    }
    */
    d.assign(maxn, 1e9);
    parent.assign(maxn, 0);
    dijkstra(s);
    sum+=d[t];
    vector<int> path2;
    tmp=t;
    while (tmp!=s){
        path2.push_back(tmp);
        tmp=parent[tmp];
    }
    path2.push_back(s);
    reverse(path2.begin(), path2.end());
    cout<< sum<< endl;
    for (int x:path1) cout<< x<< " ";
    cout<< endl;
    for (int x:path2) cout<< x<< " ";
    return 0;
}
