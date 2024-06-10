#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
using namespace std;

ll n, d[105][105], A[105][105], visited[105];

void floyd(){
    for (int k=1; k<=n; k++){
        for (int i=1; i<=n; i++){
            for (int j=1; j<=n; j++){
                d[i][j]=min(d[i][j], d[i][k]+d[k][j]);
            }
        }
    }
}

int timMin(int i){
    ll Min=1e18, id;
    for (int j=2; j<=n-1; j++){
        if (visited[j]==0 && Min>d[i][j]){
            Min=d[i][j];
            id=j;
        }
    }
    return id;
}

void solution(){
    ll ans=0, cnt=1, u=1;
    visited[1]=1;
    while (cnt!=n-1){
        cnt++;
        int v=timMin(u);
        ans+=d[u][v];
        visited[v]=1;
        u=v;
    }
    ans+=d[u][n];
    cout<< ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    for (ll i=1; i<=n; i++){
        for (ll j=1; j<=n; j++){
            cin>> A[i][j];
            if (A[i][j]!=0) d[i][j]=A[i][j];
            else d[i][j]=1e18;
        }
    }
    floyd();
    solution();
    return 0;
}
