//Tìm TPLT mạnh trên đồ thị có hướng
#include <bits/stdc++.h>
using namespace std;

int n, m, cnt=0, cc=0;
vector<int> adj[100006];
int low[10006], id[10006];
stack<int> st;

void dfs(int u, int p){
    low[u]=id[u]=++cnt;
    st.push(u);
    for (int v:adj[u]){
        if (id[v]) low[u]=min(low[u], id[v]);
        else{
            dfs(v, u);
            low[u]=min(low[u], low[v]);
        }
    }
    if (low[u]==id[u]){
        cc++;
        int v=0;
        while (v!=u){
            v=st.top();
            st.pop();
            id[v]=n+1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m;
    for (int i=1; i<=m; i++){
        int u, v; cin>> u>> v;
        adj[u].push_back(v);
    }
    for (int i=1; i<=n; i++){
        if (id[i]==0) dfs(i, 0);
    }
    cout<< cc;
    return 0;
}
