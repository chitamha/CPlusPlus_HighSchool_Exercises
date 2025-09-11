#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, m, F[35][35];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m;
    for (int i=2; i<=m; i++) F[1][i]=1;
    for (int i=2; i<=n; i++){
        for (int j=1; j<=m; j++){
            F[i][j]=1e18;
            for (int t=1; t<=j-1; t++){
                F[i][j]=min(2*F[i][j-t]+F[i-1][t], F[i][j]);
            }
        }
    }
    cout<< F[n][m];
    return 0;
}
