#include <bits/stdc++.h>
#define maxn 100005
#define MOD 1e9+7
using namespace std;

vector<vector<int>> A;
int n, m, q;

int main(){
    freopen("GRAPH4.INP", "r", stdin);
    freopen("GRAPH4.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>> n>> m>> q;
    A.resize(n);
    for (int i=1; i<=m; i++){
        int u, v;
        cin>> u>> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }
    for (int i=1; i<=q; i++){
        int u, v;
        cin>> u>> v;
        if (binary_search(A[u].begin(), A[u].end(), v))
            cout<< "YES\n";
        else cout<< "NO\n";
    }
    return 0;
}
