#include <bits/stdc++.h>
using namespace std;

int n;
int A[105][105], F[105][105];

int main(){
    cin>> n;
    for (int i=1; i<=n; i++){
        A[i][0]=0;
        A[i][n+1]=0;
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin>> A[i][j];
            if (i==1) F[1][j]=A[1][j];
        }
    }
    for (int i=2; i<=n; i++){
        for (int j=1; j<=n; j++){
            F[i][j]=max({F[i-1][j-1], F[i-1][j], F[i-1][j+1]})+A[i][j];
        }
    }
    cout<< *max_element(F[n]+1, F[n]+n+1);
    return 0;
}
