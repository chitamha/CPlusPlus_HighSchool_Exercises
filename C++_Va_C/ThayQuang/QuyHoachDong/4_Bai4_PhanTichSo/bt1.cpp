#include <bits/stdc++.h>
using namespace std;

int n, k;
long long C[1005][1005];

int main(){
    freopen("TOHOP.INP", "r", stdin);
    freopen("TOHOP.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>> n>> k;
    for (int i=0; i<=n; i++) C[i][i]=C[i][0]=1;
    for (int i=1; i<=n; i++){
        for (int j=1; j<i; j++){
            C[i][j]=C[i-1][j-1]+C[i-1][j];
        }
    }
    cout<< C[n][k];
}
