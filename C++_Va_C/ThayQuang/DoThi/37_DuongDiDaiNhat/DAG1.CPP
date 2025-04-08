#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define ill pair<int, ll>
using namespace std;

int n, m, s, t, d[300005], F[300005], color[300005], Topo[300005], cnt;
vector<ill> adj[300005];
ll MOD=1000000007;

void DFS(int u){
    color[u]=1;
    for (ill p:adj[u]){
        if (color[p.fi]==0)
            DFS(p.fi);
    }
    Topo[cnt--]=u;
    //Duyệt xong càng sớm thì ở càng cuối
}

int main(){
    freopen("DAG.INP", "r", stdin);
    freopen("DAG.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m>> s>> t;
    cnt=n;
    for (int i=1; i<=m; i++){
        int a, b, c;
        cin>> a>> b>> c;
        adj[a].push_back({b, c});
    }
    for (int i=1; i<=n; i++) if (color[i]==0) DFS(i);
    fill(d+1, d+n+1, -2e9);
    d[s]=0;
    for (int i=1; i<=n; i++){
        int u=Topo[i];
        //if (d[u]==-2e9) continue;
        for (ill p:adj[u]){
            int v=p.fi, w=p.se;
            d[v]=max(d[v], d[u]+w);
        }
    }
    if (d[t]==-2e9) cout<< "NO PATH"<< endl;
    else cout<< d[t]<< endl;
    F[s]=1;
    for (int i=1; i<=n; i++){
        int u=Topo[i];
        for (ill p:adj[u]){
            int v=p.fi;
            F[v]=(F[v]+F[u])%MOD;
        }
    }
    cout<< F[t];
    return 0;
}
