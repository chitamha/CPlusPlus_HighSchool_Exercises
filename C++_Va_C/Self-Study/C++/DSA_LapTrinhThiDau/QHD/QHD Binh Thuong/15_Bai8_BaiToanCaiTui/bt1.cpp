#include <bits/stdc++.h>
using namespace std;

int w[1005], v[1005];
int F[1005][1005];

int main(){
    int N, V;
    cin>> N>> V;
    for (int i=1; i<=N; i++) cin>> w[i];
    for (int i=1; i<=N; i++) cin>> v[i];
    F[0][0]=0;
    for (int i=1; i<=N; i++){
        for (int j=1; j<=V; j++){
            if (j>=w[i])
                F[i][j]=max(v[i]+F[i-1][j-w[i]], F[i-1][j]);
            else F[i][j]=F[i-1][j];
        }
    }
    cout<< F[N][V];
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;

int F[1005][1005];

int main(){
    int n, V;
    cin>> n>> V;
    int w[n+1], v[n+1];

    for (int i=1; i<=n; i++) cin>> w[i];
    for (int i=1; i<=n; i++) cin>> v[i];
    for (int i=0; i<=V; i++) F[0][i]=0;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=V; j++){
            if (j-w[i]>=0)
                F[i][j]=max(F[i-1][j-w[i]]+v[i], F[i-1][j]);
            else F[i][j]=F[i-1][j];
        }
    }
    cout<< F[n][V];
    return 0;
}
*/
