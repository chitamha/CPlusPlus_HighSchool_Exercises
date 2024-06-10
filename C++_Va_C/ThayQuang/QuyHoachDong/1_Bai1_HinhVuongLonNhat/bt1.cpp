#include <bits/stdc++.h>
using namespace std;

int n, m;

int main(){
    //freopen("HINHVUONG.INP", "r", stdin);
    //freopen("HINHVUONG.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>> n>> m;
    int A[n+1][m+1];
    int F[n+1][m+1];
    memset(A, 0, sizeof A);
    memset(F, 0, sizeof F);
    int ans=0;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin>> A[i][j];
            if (A[i][j]==1)
                F[i][j]=max(F[i-1][j], F[i][j-1])+1;
            ans=max(ans, F[i][j]);
        }
    }
    cout<< ans*ans;
    return 0;
}
