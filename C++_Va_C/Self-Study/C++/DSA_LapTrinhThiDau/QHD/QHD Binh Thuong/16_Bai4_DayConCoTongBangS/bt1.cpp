#include <bits/stdc++.h>
using namespace std;

int n, S;
int A[205];
int F[205][50005];

int main(){
    cin>> n>> S;
    for (int i=1; i<=n; i++){
        cin>> A[i];
    }
    for (int i=1; i<=n; i++) F[i][0]=true;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=S; j++){
            if (j>=A[i])
                F[i][j]=F[i-1][j]||F[i-1][j-A[i]];
            else F[i][j]=F[i-1][j];
        }
    }
    cout<< F[n][S];
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, s;
    cin>> n>> s;
    int A[n+1];
    for (int i=1; i<=n; i++) cin>> A[i];
    int F[n+1][s+1];
    for (int i=0; i<=n; i++) F[i][0]=0;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=s; j++){
            if (j>=A[i]){
                F[i][j]=F[i-1][j-A[i]]||F[i-1][j];
            } else F[i][j]=F[i-1][j];
        }
    }
    cout<< F[n][s];
    return 0;
}
*/
