#include <bits/stdc++.h>
#define maxn 105
using namespace std;

int m, n, k, X[maxn][maxn], F[maxn][maxn];
vector<int> A, H;
vector<int> B, C;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> m>> n>> k;
    A.resize(m+1); B.resize(n+1);
    H.resize(m+1); C.resize(n+1);
    for (int i=1; i<=m; i++) cin>> A[i];
    for (int i=1; i<=n; i++) cin>> B[i];
    for (int i=1; i<=k; i++){
        int x, y; cin>> x>> y;
        X[x][y]=1;
    }
    memset(F, 62, sizeof F);
    for (int i=1; i<=m; i++) F[i][0]=0;
    for (int i=1; i<=n; i++) F[0][i]=0;
    for (int i=1; i<=m; i++){
        for (int j=1; j<=n; j++){
            if (X[i][j]==0){
                F[i][j]=min({F[i][j], F[i-1][j], F[i][j-1], F[i-1][j-1]});
                /*
                if (H[i]==0 && C[j]==0) F[i][j]=min(F[i][j], F[i-1][j-1]);
                else if (H[i]==1 && C[j]==0) F[i][j]=min(F[i][j], F[i][j-1]);
                else if (H[i]==0 && C[j]==1) F[i][j]=min(F[i][j], F[i-1][j]);
                else if (H[i]==1 && C[j]==1) F[i][j]=min({F[i][j], F[i-1][j]+A[i], F[i][j-1]+B[j]});
                */
            } else{
                if (H[i]==0 && C[j]==0){
                    F[i][j]=min(F[i][j], F[i-1][j-1]+min(A[i], B[j]));
                    if (A[i]<B[j]) H[i]=1;
                    else C[j]=1;
                } else{
                    if (F[i-1][j]+A[i]<F[i][j-1]+B[j]){
                        F[i][j]=F[i-1][j]+A[i];
                        H[i]=1;
                    } else{
                        F[i][j]=F[i][j-1]+B[j];
                        C[j]=1;
                    }
                }
            }
        }
    }
    cout<< F[m][n];
    return 0;
}
