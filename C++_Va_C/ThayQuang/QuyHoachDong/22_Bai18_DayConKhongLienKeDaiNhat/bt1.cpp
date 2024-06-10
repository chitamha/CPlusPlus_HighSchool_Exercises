#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 1006
using namespace std;

int n, m;
int F[maxn][maxn], A[maxn], B[maxn];

int main(){
    freopen("LNACS.INP", "r", stdin);
    freopen("LNACS.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m;
    for (int i=1; i<=n; i++) cin>> A[i];
    for (int i=1; i<=m; i++) cin>> B[i];
    A[0]=-1; B[0]=-2;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (A[i]==B[j] && A[i-1]!=B[j-1]) F[i][j]=F[i-1][j-1]+1;
            else F[i][j]=max(F[i-1][j], F[i][j-1]);
        }
    }
    cout<< F[n][m];
    return 0;
}
