#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
using namespace std;

ll n, d[105][105], A[105][105], visited[105];

void dijkstra(ll i){
    priority_queue<llll, vector<llll>, greater<llll>> pq;
    d[i][i]=0;
    pq.push({0, i});
    while (!pq.empty()){
        ll u=pq.top().se;
        ll kc=pq.top().fi;
        pq.pop();
        if (kc>d[i][u]) continue;
        for (ll v=1; v<=n; v++){
            if (A[u][v]==0) continue;
            if (d[i][v]>d[i][u]+A[u][v]){
                d[i][v]=d[i][u]+A[u][v];
                pq.push({d[i][v], v});
            }
        }
    }
}

int tim(int i){
    ll Min=1e18, id;
    //Tìm j chưa thăm và có d[i][j] ngắn nhất
    for (int j=2; j<=n-1; j++){
        if (visited[j]==0 && i!=j && Min>d[i][j]){
            Min=d[i][j];
            id=j;
        }
    }
    return id;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    for (ll i=1; i<=n; i++){
        for (ll j=1; j<=n; j++){
            cin>> A[i][j];
            d[i][j]=1e18;
        }
    }
    for (ll i=1; i<=n; i++) dijkstra(i);
    visited[1]=1;
    ll cnt=1, u=1, dis=0;
    while (cnt!=n-1){
        cnt++;
        int v=tim(u);
        visited[v]=1;
        dis+=d[u][v];
        //cout<< dis<< " "<< u<< " "<< v<< endl;
        u=v;
    }
    dis+=d[u][n];
    cout<< dis;
    return 0;
}
