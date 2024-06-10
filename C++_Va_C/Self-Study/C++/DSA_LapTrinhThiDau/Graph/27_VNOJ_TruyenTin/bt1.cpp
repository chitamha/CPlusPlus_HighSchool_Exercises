#include <bits/stdc++.h>
#define maxn 1000006
using namespace std;

int n, m, cnt=0, cc=0;
vector<int> adj[maxn];
int id[maxn], low[maxn], tplt[maxn];
bool visited[maxn], mark[maxn];
stack<int> st;

void check(int u){
    visited[u]=true;
    for (int v:adj[u]){
        if (visited[v]==false)
            check(v);
    }
}

void dfs(int u){
    id[u]=low[u]=++cnt;
    st.push(u);
    for (int v:adj[u]){
        if (id[v]) low[u]=min(low[u], id[v]);
        else{
            dfs(v);
            low[u]=min(low[u], low[v]);
        }
    }
    if (id[u]==low[u]){
        cc++;
        int v=0;
        while (v!=u){
            v=st.top();
            st.pop();
            tplt[v]=cc;
            id[v]=n+1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m;
    for (int i=1; i<=m; i++){
        int u, v;
        cin>> u>> v;
        adj[u].push_back(v);
    }
    for (int i=1; i<=n; i++)
        if (id[i]==0) dfs(i);
    for (int i=1; i<=n; i++){
        memset(visited, false, sizeof visited);
        check(i);
        for (int j=1; j<=n; j++){
            if (tplt[i]!=tplt[j] && visited[j]==true)
                mark[tplt[j]]=true;
        }
    }
    int ans=0;
    for (int i=1; i<=cc; i++)
        if (mark[i]==false) ans++;
    cout<< ans;
    return 0;
}
