#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

int n, m, k;
double d[1005][15];
vector<pair<int, int>> adj[100005];
struct mt{
    int u, i;
    double dis;
    friend bool operator < (mt a, mt b){
        return a.dis>b.dis;
    }
};

void dijkstra(){
    for (int i=1; i<=n; i++){
        for (int j=0; j<=k; j++){
            d[i][j]=1000000000.0;
        }
    }
    priority_queue<mt> pq;
    for (int j=0; j<=k; j++) d[1][j]=0;
    pq.push({1, 0, 0});
    while (!pq.empty()){
        int u=pq.top().u, i=pq.top().i;
        double kc=pq.top().dis;
        pq.pop();
        if (kc>d[u][i]) continue;
        for (auto p:adj[u]){
            int v=p.fi;
            double w=p.se*1.0;
            for (int j=i; j<=k; j++){
                if (d[v][j]>d[u][i]+w){
                    d[v][j]=d[u][i]+w;
                    pq.push({v, j, d[v][j]});
                }
                w/=2.0;
            }
        }
    }
}

int main(){
    cin>> n>> m>> k;
    for (int i=1; i<=m; i++){
        int u, v, w;
        cin>> u>> v>> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dijkstra();
    double ans=1000000000.0;
    for (int i=0; i<=k; i++) ans=min(ans, d[n][i]);
    cout<< fixed<< setprecision(2)<< ans;
    return 0;
}
