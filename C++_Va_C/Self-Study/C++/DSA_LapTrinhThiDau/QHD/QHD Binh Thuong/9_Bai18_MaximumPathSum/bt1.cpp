#include <bits/stdc++.h>
#define maxn 505
using namespace std;

int n, m;
int A[maxn][maxn], F[maxn][maxn];

int main(){
    cin>> n>> m;
    for (int i=0; i<=n; i++){
        A[i][0]=0;
    }
    for (int j=0; j<=m; j++){
        A[0][j]=0;
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin>> A[i][j];
        }
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            F[i][j]=max({F[i-1][j], F[i][j-1], F[i-1][j-1]})+A[i][j];
        }
    }
    cout<< F[n][m];
    return 0;
}
