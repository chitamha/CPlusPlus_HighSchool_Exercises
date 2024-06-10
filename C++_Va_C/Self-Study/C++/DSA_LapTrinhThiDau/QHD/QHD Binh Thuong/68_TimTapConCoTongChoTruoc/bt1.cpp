#include <bits/stdc++.h>
#define maxn 10005
using namespace std;

int A[maxn];
int F[maxn][maxn];
int t, n, s;

int main(){
    cin>> t;
    while (t--){
        cin>> n>> s;
        for (int i=1; i<=n; i++) cin>> A[i];
        for (int i=1; i<=n; i++){
            for (int j=1; j<=s; j++){
                F[i][j]=0;
            }
        }
        for (int i=0; i<=n; i++){
            F[i][0]=1;
        }
        for (int i=1; i<=n; i++){
            for (int j=1; j<=s; j++){
                if (j-A[i]>=0)
                    F[i][j]=F[i-1][j] || F[i-1][j-A[i]];
                else F[i][j]=F[i-1][j];
            }
        }
        if (F[n][s]) cout<< "YES\n";
        else cout<< "NO\n";
    }
    return 0;
}
