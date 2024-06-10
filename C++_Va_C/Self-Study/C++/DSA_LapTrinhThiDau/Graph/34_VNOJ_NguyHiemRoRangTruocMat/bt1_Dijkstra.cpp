#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
using namespace std;

ll n, m, d[105][105], A[10005], cuop[105][105];

void dijkstra(int i){
    priority_queue<llll, vector<llll>, greater<llll>> pq;
    d[i][i]=0;
    pq.push({0, i});
    while (!pq.empty()){
        int u=pq.top().se;
        ll kc=pq.top().fi;
        pq.pop();
        if (kc>d[i][u]) continue;
        for (int v=1; v<=n; v++){
            if (d[i][v]>d[i][u]+cuop[u][v]){
                d[i][v]=d[i][u]+cuop[u][v];
                pq.push({d[i][v], v});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m;
    for (int i=1; i<=m; i++) cin>> A[i];
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin>> cuop[i][j];
            d[i][j]=1e18;
        }
    }
    for (int i=1; i<=n; i++) dijkstra(i);
    ll mindis=d[1][A[1]];
    //cout<< mindis<< " "<< d[1][A[1]]<< endl;
    for (int i=1; i<=m-1; i++){
        mindis+=d[A[i]][A[i+1]];
        //cout<< mindis<< " "<< d[A[i]][A[i+1]]<< endl;
    }
    mindis+=d[A[m]][n];
    //cout<< mindis<< " "<< d[A[m]][n]<< endl;
    cout<< mindis;
    return 0;
}
