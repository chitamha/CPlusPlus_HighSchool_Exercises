#include <bits/stdc++.h>
#define maxn 10006
using namespace std;

int n, m, cnt=0;
vector<int> adj[maxn];
int tplt[maxn];
bool visited[maxn];

void dfs(int u){
    visited[u]=true;
    tplt[u]=cnt;
    for (int v:adj[u]){
        if (visited[v]==false)
            dfs(v);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m;
    for (int i=2; i<=n; i++){
        int v, k;
        cin>> v>> k;
        if (k==2) continue;
        adj[i].push_back(v);
        adj[v].push_back(i);
    }
    for (int i=1; i<=n; i++){
        cnt++;
        if (visited[i]==false) dfs(i);
    }
    while (m--){
        int x, y; cin>> x>> y;
        if (tplt[x]!=tplt[y]) cout<< "YES"<< endl;
        else cout<< "NO"<< endl;
    }
    return 0;
}
