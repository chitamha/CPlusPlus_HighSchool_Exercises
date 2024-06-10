#include <bits/stdc++.h>
#define ll long long
#define maxn 1000006
using namespace std;

ll n, m, s, t;
vector<pair<ll, ll>> adj[maxn];
vector<ll> d(maxn, 1e9);
vector<ll> parent(maxn);
vector<ll> path;
//Mang luu khoang cach duong di

void dijkstra(ll s){
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<int, int>>> Q;
    Q.push({0, s});
    //{khoang cach, dinh}
    d[s]=0;
    while (!Q.empty()){
        //Chon ra dinh co khoang cach tu s den no nho nhat
        auto top=Q.top(); Q.pop();
        ll kc=top.first, u=top.second;
        //Khong cap nhat lai neu kc>d[u]
        //{12, 3}, d[3]=9, 12>9 => bo qua
        if (kc>d[u]) continue;
        //Thong qua dinh u da biet khoang cach ngan nhat tinh tu s, cap
        //nhap khoang cach voi cac dinh ke voi u
        for (auto p:adj[u]){
            ll v=p.first, w=p.second;
            if (d[v]>d[u]+w){
                parent[v]=u;
                d[v]=d[u]+w;
                Q.push({d[v], v});
            }
        }
    }
    for (ll i=1; i<=n; i++){
        cout<< d[i]<< " ";
    }
    cout<< endl;
}

int main(){
    cin>> n>> m>> s>> t;
    for (ll i=1; i<=m; i++){
        int u, v, w;
        cin>> u>> v>> w;
        adj[u].push_back({v, w});
        //adj[v].push_back({u, w});
    }
    dijkstra(s);
    while (t!=s){
        path.push_back(t);
        t=parent[t];
    }
    path.push_back(s);
    reverse(begin(path), end(path));
    for (ll i:path) cout<< i<< " ";
    return 0;
}
