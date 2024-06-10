#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
using namespace std;
using ll=long long;

ll n, s;
int A[1005][1005];
vector<ll> d(1005, 1e9);
vector<ll> parent(1005);

void dijkstra(ll s){
    priority_queue<llll, vector<llll>, greater<llll>> Q;
    d[s]=0;
    Q.push({0, s});
    while (!Q.empty()){
        auto top=Q.top(); Q.pop();
        ll kc=top.fi, u=top.se;
        if (kc>d[u]) continue;
        for (ll v=0; v<n; v++){
            if (A[u][v]!=0 && d[v]>d[u]+A[u][v]){
                d[v]=d[u]+A[u][v];
                parent[v]=u;
                Q.push({d[v], v});
            }
        }
    }
}

int main(){
    cin>> n>> s;
    for (ll i=0; i<n; i++){
        for (ll j=0; j<n; j++){
            cin>> A[i][j];
        }
    }
    dijkstra(s);
    cout<< "Cac duong di tu "<< s<< " den cac dinh con lai:"<< endl;
    for (ll i=0; i<n; i++){
        if (i!=s && d[i]!=1e9){
            ll en=i;
            cout<< "("<< s<< ","<< en<< ")="<< d[en]<< " duong di: ";
            while (en!=s){
                cout<< en<< " <- ";
                en=parent[en];
            }
            cout<< s<< endl;
        }
    }
    return 0;
}
