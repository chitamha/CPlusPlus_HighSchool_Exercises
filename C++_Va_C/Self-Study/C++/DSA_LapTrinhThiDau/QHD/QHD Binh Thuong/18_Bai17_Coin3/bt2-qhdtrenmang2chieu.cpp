#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int n, x;
int A[102];
long long F[102][1000006];

int main(){
    cin>> n>> x;
    for (int i=1; i<=n; i++){
        cin>> A[i];
    }
    for (int i=0; i<=n; i++) F[i][0]=1;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=x; j++){
            if (j>=A[i]){
                F[i][j]=F[i-1][j]+F[i][j-A[i]];
            } else{
                F[i][j]=F[i-1][j];
            }
        }
    }
    cout<< F[n][x];
    return 0;
}
