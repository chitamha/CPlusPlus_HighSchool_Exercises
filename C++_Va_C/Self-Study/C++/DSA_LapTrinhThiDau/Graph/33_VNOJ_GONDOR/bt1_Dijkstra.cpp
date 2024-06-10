#include <bits/stdc++.h>
#define maxn 105
#define fi first
#define se second
#define dint pair<double, int>
using namespace std;

int n, s[maxn], visited[maxn];
vector<double> d(maxn);
vector<pair<int, int>> toado(maxn);
vector<int> adj[maxn];

double dis(int i, int j){
    double x=toado[j].fi-toado[i].fi;
    double y=toado[j].se-toado[i].se;
    return sqrt(pow(x, 2)+pow(y, 2));
}

void dijkstra(){
    priority_queue<dint, vector<dint>, greater<dint>> pq;
    d[1]=0;
    pq.push({0, 1});
    while (!pq.empty()){
        int u=pq.top().se;
        double kc=pq.top().fi;
        pq.pop();
        if (kc>d[u]) continue;
        visited[u]=1;
        for (int v:adj[u]){
            if (s[u]==0) break;
            if (visited[v]==1) continue;
            s[u]--;
            double tmpdis=dis(u, v);
            if (d[v]>d[u]+tmpdis){
                d[v]=d[u]+tmpdis;
                pq.push({d[v], v});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    for (int i=1; i<=n; i++){
        cin>> toado[i].fi>> toado[i].se>> s[i];
        for (int j=1; j<=n-1; j++){
            int tmp; cin>> tmp;
            adj[i].push_back(tmp);
        }
        d[i]=1000000000.0;
    }
    dijkstra();
    for (int i=1; i<=n; i++)
        cout<< fixed<< setprecision(6)<< d[i]<< endl;
    return 0;
}
