#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 1006
using namespace std;

ll m, n, A[maxn][maxn];
ll f1[maxn][maxn], f2[maxn][maxn], g1[maxn][maxn], g2[maxn][maxn];
/*
https://www.spoj.com/PTIT/problems/P154PROD/
Gọi f1[i,j] là tổng số điểm đi từ ô (1,1) đến ô (i,j)
Gọi f2[i,j] là tổng số điểm đi từ ô (m,n) đến ô (i,j)
Gọi g1[i,j] là tổng số điểm đi từ ô (m,1) đến ô (i,j)
Gọi g2[i,j] là tổng số điểm đi từ ô (1,n) đến ô (i,j)
Kết quả là max(f1[i,j-1]+f2[i,j+1]+g1[i+1,j]+g2[i-1,j],
f1[i-1,j]+f2[i+1,j]+g1[i,j-1]+g2[i,j+1])
*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> m>> n;
    for (ll i=1; i<=m; i++) for (ll j=1; j<=n; j++) cin>> A[i][j];
    for (ll i=1; i<=m; i++){
        for (ll j=1; j<=n; j++) f1[i][j]=max(f1[i-1][j], f1[i][j-1])+A[i][j];
    }
    for (ll i=m; i>=1; i--){
        for (ll j=n; j>=1; j--) f2[i][j]=max(f2[i+1][j], f2[i][j+1])+A[i][j];
    }
    for (ll i=m; i>=1; i--){
        for (ll j=1; j<=n; j++) g1[i][j]=max(g1[i+1][j], g1[i][j-1])+A[i][j];
    }
    for (ll i=1; i<=m; i++){
        for (ll j=n; j>=1; j--) g2[i][j]=max(g2[i-1][j], g2[i][j+1])+A[i][j];
    }
    ll ans=0;
    for (ll i=2; i<=m-1; i++){
        for (ll j=2; j<=n-1; j++) ans=max({ans, f1[i][j-1]+f2[i][j+1]+g1[i+1][j]+g2[i-1][j], f1[i-1][j]+f2[i+1][j]+g1[i][j-1]+g2[i][j+1]});
    }
    cout<< ans;
    return 0;
}
