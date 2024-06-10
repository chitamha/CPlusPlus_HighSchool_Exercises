#include <bits/stdc++.h>
using namespace std;

int n;
int A[105][105], F[105][105];

int main(){
    cin>> n;
    for (int i=1; i<=n; i++){
        A[i][0]=-1e9;
        A[i][n+1]=-1e9;
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin>> A[j][i];
        }
    }
    for (int i=1; i<=n; i++) F[1][i]=A[1][i];
    for (int i=2; i<=n; i++){
        for (int j=1; j<=n; j++){

            F[i][j]=max({F[i-1][j-1], F[i-1][j], F[i-1][j+1]})+A[i][j];
        }
    }
    cout<< *max_element(F[n]+1, F[n]+n+1);
    return 0;
}
