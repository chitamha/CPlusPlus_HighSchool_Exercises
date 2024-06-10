#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 10006
using namespace std;

int n, LF[maxn], F[maxn];
/*
Gọi F[u] là cây con lớn nhất mà u quản lý (có thể đi qua u hoặc không)
Gọi LF[u] là khoảng cách từ u đến lá xa nhất mà u quản lý
*/
bool visited[maxn];
vector<vector<int>> adj;

void DFS(int u){
    int max1=0, max2=0;
    visited[u]=true;
    for (int v:adj[u]){
        if (visited[v]==false){
            DFS(v);
            F[u]=max(F[u], F[v]);
            LF[u]=max(LF[u], LF[v]+1);
            if (LF[v]>max2){
                if (LF[v]>max1){
                    max2=max1; max1=LF[v];
                } else max2=LF[v];
            }

        }
    }
    F[u]=max(F[u], max1+max2+1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n; adj.resize(n+1);
    for (int i=1; i<n; i++){
        int u, v; cin>> u>> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(visited, false, sizeof visited);
    for (int i=1; i<=n; i++) F[i]=LF[i]=1;
    DFS(1);
    cout<< F[1]-1;
    return 0;
}
