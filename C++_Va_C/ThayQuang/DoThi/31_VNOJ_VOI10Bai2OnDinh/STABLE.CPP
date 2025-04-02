#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, m, s, ans=0, d[10005][5];
vector<int> adj[10005];

void Dijkstra(){
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, s});
    d[s][1]=0;
    d[s][2]=1;
    while (!pq.empty()){
        int u=pq.top().se, dis=pq.top().fi;
        pq.pop();
        if (dis>d[u][1]) continue;
        for (int v:adj[u]){
            if (d[v][1]>=d[u][1]+1){
                d[v][1]=d[u][1]+1;
                d[v][2]=min(2, d[v][2]+d[u][2]);
                pq.push({d[v][1], v});
            }
        }
    }
}

int main(){
    //freopen("STABLE.INP", "r", stdin);
    //freopen("STABLE.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m>> s;
    map<ii, int> mp;
    for (int i=1; i<=m; i++){
        int u, v;
        cin>> u>> v;
        if (mp[{u, v}]==0) adj[u].push_back(v);
        mp[{u, v}]=1;
    }
    for (int i=1; i<=n; i++) d[i][1]=1e9;
    Dijkstra();
    for (int i=1; i<=n; i++) if (d[i][2]>=2) ans++;
    cout<< ans;
    return 0;
}
