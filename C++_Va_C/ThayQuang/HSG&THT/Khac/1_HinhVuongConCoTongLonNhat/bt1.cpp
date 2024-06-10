#include <bits/stdc++.h>
#define maxn 10002
using namespace std;

long long A[maxn][maxn], F[maxn][maxn];
long long t, n, k;

int main(){
    cin>> t;
        while (t--){
        cin>> n>> k;
        memset(F, 0, sizeof F);
        for (int i=1; i<=n; i++){
            for (int j=1; j<=n; j++){
                cin>> A[i][j];
                F[i][j]=F[i-1][j]+F[i][j-1]-F[i-1][j-1]+A[i][j];
            }
        }
        long long Max=-1e9;
        for (int i=1; i<=n-k+1; i++){
            for (int j=1; j<=n-k+1; j++){
                Max=max(Max, F[i][j]+F[i-k][j-k]-F[i][j-k]-F[i-k][j]);

            }
        }
        cout<< Max<< endl;
    }
}
