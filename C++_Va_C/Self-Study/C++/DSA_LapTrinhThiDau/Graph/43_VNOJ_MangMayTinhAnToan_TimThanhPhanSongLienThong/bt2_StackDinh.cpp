#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 30006
using namespace std;

int n, m, id[maxn], low[maxn], cnt=0, ans=1;
vector<int> adj[maxn];
stack<int> st;

//Tim thanh phan song lien thong nhieu dinh nhat
void dfs(int u, int p){
    id[u]=low[u]=++cnt;
    st.push(u);
    for (int v:adj[u]){
        //if (v==p) continue;
        if (id[v]) low[u]=min(low[u], id[v]);
        else{
            dfs(v, u);
            low[u]=min(low[u], low[v]);
            if (low[v]>=id[u]){
                int dem=1, tmp=0;
                while (tmp!=v){
                    tmp=st.top();
                    st.pop();
                    dem++;
                }
                if (dem>=2) ans=max(ans, dem);
            }
        }
    }
}

int main(){
    //freopen("text1.inp", "r", stdin);
    //freopen("text1.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m;
    for (int i=1; i<=m; i++){
        int u, v; cin>> u>> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i=1; i<=n; i++) if (id[i]==0) dfs(i, 0);
    //for (int i=1; i<=n; i++) cout<< i<< "; id: "<< id[i]<< "; low: "<< low[i]<< endl;
    cout<< ans;
    return 0;
}
