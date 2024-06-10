#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
using namespace std;
using ll=long long;

ll n, s, t;
int A[1005][1005];
vector<ll> d(1005, 1e9);
vector<ll> parent(1005);
vector<ll> path;

void dijkstra(ll s){
    priority_queue<llll, vector<llll>, greater<llll>> Q;
    d[s]=0;
    Q.push({0, s});
    while (!Q.empty()){
        auto top=Q.top(); Q.pop();
        ll kc=top.fi, u=top.se;
        if (kc>d[u]) continue;
        for (ll v=1; v<=n; v++){
            if (A[u][v]!=0 && d[v]>d[u]+A[u][v]){
                d[v]=d[u]+A[u][v];
                parent[v]=u;
                Q.push({d[v], v});
            }
        }
    }
}

int main(){
    freopen("DIJKSTRA.INP", "r", stdin);
    freopen("DIJKSTRA.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>> n;
    cin>> s>> t;
    for (ll i=1; i<=n; i++){
        for (ll j=1; j<=n; j++){
            cin>> A[i][j];
        }
    }
    dijkstra(s);
    if (d[t]!=1e9){
        cout<< "Duong di ngan nhat la: "<< d[t]<< endl;
        while (s!=t){
            path.push_back(t);
            t=parent[t];
        }
        path.push_back(s);
        reverse(begin(path), end(path));
        for (int i:path){
            cout<< i;
            if (i!=*path.rbegin()) cout<< " -> ";
        }
    } else cout<< "Khong co duong di tu "<< s<< " den "<< t;
    return 0;
}
