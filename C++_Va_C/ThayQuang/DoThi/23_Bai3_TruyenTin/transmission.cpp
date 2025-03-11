#include <bits/stdc++.h>
#define ii pair<int, int>
#define ll long long
#define fi first
#define se second
using namespace std;

int n, m, ans=0, visited[250], P[250];
ii Located[250];

double Dis(int x, int y){
    return sqrt(pow(1.0*(Located[x].fi-Located[y].fi), 2)+pow(1.0*(Located[x].se-Located[y].se), 2));
}

void bfs(int x){
    queue<int> q;
    visited[x]=1;
    q.push(x);
    while (!q.empty()){
        int u=q.front(); q.pop();
        for (int v=1; v<=n; v++){
            if (!visited[v] && Dis(u, v)<=1.0*P[u]){
                visited[v]=1;
                q.push(v);
            }
        }
    }
}

int main(){
    freopen("transmission.inp", "r", stdin);
    freopen("transmission.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    for (int i=1; i<=n; i++) cin>> Located[i].fi>> Located[i].se>> P[i];
    for (int i=1; i<=n; i++){
        bfs(i);
        int cnt=0;
        for (int j=1; j<=n; j++){
            if (visited[j]==1) cnt++;
        }
        ans=max(ans, cnt);
        memset(visited, 0, sizeof visited);
    }
    cout<< ans;
    return 0;
}
