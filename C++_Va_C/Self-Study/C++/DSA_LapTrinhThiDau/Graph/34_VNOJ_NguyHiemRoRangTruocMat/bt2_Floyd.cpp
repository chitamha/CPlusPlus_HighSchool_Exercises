#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
using namespace std;

ll n, m, d[105][105], A[105][105];
vector<int> path;

void floyd(){
    for (int k=1; k<=n; k++){
        for (int i=1; i<=n; i++){
            for (int j=1; j<=n; j++){
                d[i][j]=min(d[i][j], d[i][k]+d[k][j]);
            }
        }
    }
}

void solution(){
    ll mindis=d[1][path[1]]+d[path[m]][n];
    for (int i=1; i<m; i++) mindis+=d[path[i]][path[i+1]];
    cout<< mindis;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m; path.resize(m+1);
    for (int i=1; i<=m; i++) cin>> path[i];
    for (ll i=1; i<=n; i++){
        for (ll j=1; j<=n; j++){
            cin>> A[i][j];
            d[i][j]=A[i][j];
        }
    }
    floyd();
    solution();
    return 0;
}
