#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define doull pair<double, ll>
#define dou double
#define inf (double) 1e9
using namespace std;

ll n, w, visited[1005][1005]; dou m;
vector<pair<ll, ll>> toado(1005);
vector<pair<ll, dou>> adj[1005];
dou d[1005];

dou dis(ll i, ll j){
    dou x=toado[i].fi-toado[j].fi;
    dou y=toado[i].se-toado[j].se;
    return (dou)sqrt(x*x+y*y);
}

void dijkstra(ll i){
    priority_queue<doull, vector<doull>, greater<doull>> pq;
    d[i]=0.0;
    pq.push({0.0, i});
    while (!pq.empty()){
        ll u=pq.top().se;
        dou kc=pq.top().fi;
        pq.pop();
        if (kc>d[u]) continue;
        for (pair<ll, dou> p:adj[u]){
            ll v=p.fi; dou w=p.se;
            //cout<< "Truoc "<< u<< " "<< v<< " "<< w<< " "<< d[v]<< "\n";
            if (d[v]>d[u]+w){
                d[v]=d[u]+w;
                pq.push({d[v], v});
            }
            //cout<< "Sau "<< u<< " "<< v<< " "<< w<< " "<< d[v]<< "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> w>> m;
    for (ll i=1; i<=n; i++) cin>> toado[i].fi>> toado[i].se;
    for (ll i=1; i<=w; i++){
        ll u, v; cin>> u>> v;
        adj[u].push_back({v, 0.0});
        adj[v].push_back({u, 0.0});
        visited[u][v]=visited[v][u]=1;
    }
    for (ll i=1; i<=n; i++){
        d[i]=1000000000.0;
        for (ll j=1; j<=n; j++){
            if (i!=j && visited[i][j]==0 && visited[j][i]==0){
                dou di=dis(i, j);
                if (di<=m){
                    adj[i].push_back({j, di});
                    adj[j].push_back({i, di});
                }
                visited[i][j]=visited[j][i]=1;
            }
        }
    }
    //cout<< "Dijkstra"<< "\n";
    dijkstra(1);
    /*
    cout<< "\n"<< "\n";
    for (ll i=1; i<=n; i++){
        for (auto p:adj[i]) cout<< i<< " "<< p.fi<< " "<< p.se<< "\n";
    }
    cout<< "Khoang cach tu 1"<< "\n";
    for (ll i=1; i<=n; i++) cout<< fixed<< setprecision(4)<< d[i]<< " ";
    cout<< "\n";
    */
    if (d[n]!=1000000000.0)cout<< (ll)((long dou)d[n]*1000);
    else cout<< -1;
    return 0;
}
