#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
using namespace std;

int n, m, cau=0, timeDFS=0, id[20005], low[20005], Khop[20005], stplt=0;
vector<int> adj[20005];

void DFS(int u, int pre) {
    int child = 0; //Số lượng con trực tiếp của đỉnh u trong cây DFS
    id[u] = low[u] = ++timeDFS;
    for (int v : adj[u]) {
        if (v == pre) continue;
        if (!id[v]) {
            DFS(v, u);
            low[u] = min(low[u], low[v]);
            //if (low[v] == id[v]) cau++;
            child++;
            if (u == pre) { //Nếu u là đỉnh gốc của cây DFS
                if (child >= 2) Khop[u] = child-1;
            } else if (low[v] >= id[u]) Khop[u] = child;
        }
        else low[u] = min(low[u], id[v]);
    }
}

/*
void DFS(int u, int p){
    //cout<< u<< endl;
    id[u]=low[u]=++cnt;
    int node=(p!=0);
    for (int v:adj[u]){
        if (v==p) continue;
        if (id[v]==0){
            DFS(v, u);
            low[u]=min(low[u], low[v]);
            //if (low[v]>=id[v]) cau++;
            if (low[v]>=id[u]) node++;
        } else low[u]=min(low[u], id[v]);
    }
    if (node>=2) Khop[u]=node;
}
*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m;
    for (int i=1; i<=m; i++){
        int u, v; cin>> u>> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i=1; i<=n; i++){
        if (id[i]==0){
            stplt++;
            DFS(i, i);
        }
    }
    //cout<< "STPLT: "<< stplt<< "\n";
    for (int i=1; i<=n; i++){
        //cout<< i<< ": ";
        cout<< stplt+Khop[i]<< "\n";
    }
    return 0;
}
