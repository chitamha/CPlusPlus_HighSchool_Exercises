#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin>> n>> m;
    int A[n+1][n+1];
    memset(A, 0, sizeof A);
    while (m--){
        int u, v;
        cin>> u>> v;
        A[u][v]=1;
        A[v][u]=1;
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cout<< A[i][j]<< " ";
        }
        cout<< endl;
    }
    return 0;
}
