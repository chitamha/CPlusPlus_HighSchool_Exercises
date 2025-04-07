#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define llll pair<ll, ll>
using namespace std;

ll n, m, k, NorDis[100005], ShopDis[100005], Shop[100005], origin[100005];
vector<llll> adj[100005];

void Dijkstra(){
    memset(NorDis, 62, sizeof NorDis);
    memset(ShopDis, 62, sizeof ShopDis);
    //NorDis: chi phí ngắn nhất để từ một tiệm trà sữa bất kì đến i
    //ShopDis: chi phí ngắn nhất để từ một tiệm trà sữa bất kì đến một tiệm trà sữa i
    priority_queue<llll, vector<llll>, greater<llll>> pq;
    for (int i=1; i<=n; i++){
        if (Shop[i]){
            NorDis[i]=0;
            pq.push({0, i});
            origin[i]=i;
        }
    }
    while (!pq.empty()){
        ll u=pq.top().se, dis=pq.top().fi;
        pq.pop();
        if (dis>NorDis[u]) continue;
        for (llll p:adj[u]){
            ll v=p.fi, w=p.se;
            if (NorDis[v]>NorDis[u]+w){
                NorDis[v]=NorDis[u]+w;
                pq.push({NorDis[v], v});
                origin[v]=origin[u];
            }
            else{
                //NorDis[u], NorDis[v] đã tối ưu và cạnh (u, v) đã không sử dụng khi tìm Min NorDis[v]
                //CẬP NHẬT SHOPDIS 2 NGUỒN
                //Cập nhật ShopDis của origin[u] và origin[v] nếu hai nguồn khác nhau
                //và hai nguồn (origin[u] và origin[v]) đã xác định
                if (origin[u]!=origin[v] && origin[u] && origin[v]){
                    ShopDis[origin[u]]=min(ShopDis[origin[u]], NorDis[u]+NorDis[v]+w);
                    ShopDis[origin[v]]=min(ShopDis[origin[v]], NorDis[u]+NorDis[v]+w);
                }
            }
        }
    }
}

int main(){
    freopen("MILKTEA.INP", "r", stdin);
    freopen("MILKTEA.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m>> k;
    for (ll i=1; i<=m; i++){
        ll u, v, w; cin>> u>> v>> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    for (ll i=1; i<=k; i++){
        ll p, t; cin>> p>> t;
        Shop[p]=t+1;
    }
    Dijkstra();
    for (int i=1; i<=n; i++){
        if (Shop[i]==2) cout<< ShopDis[i]<< " ";
        else cout<< NorDis[i]<< " ";
    }
    return 0;
}
