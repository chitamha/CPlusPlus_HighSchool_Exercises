#include <bits/stdc++.h>
#define maxn 10006
using namespace std;

int n, k;
int ph[maxn], hs[maxn], F[maxn][maxn];

int main(){
    cin>> n>> k;
    for (int i=1; i<=n; i++) cin>> ph[i];
    for (int i=1; i<=k; i++) cin>> hs[i];
    if (n==k){
        int sum=0;
        for (int i=1; i<=n; i++) sum+=abs(hs[i]-ph[i]);
        return cout<< sum, 0;
    }
    for (int i=1; i<=k; i++){
        for (int j=i; j<=n; j++){
            if (i==j) F[i][j]=F[i-1][j-1]+abs(hs[i]-ph[j]);
            else F[i][j]=min(F[i][j-1], F[i-1][j-1]+abs(hs[i]-ph[j]));
        }
    }
    /*
    for (int i=1; i<=k; i++){
        for (int j=1; j<=n; j++) cout<< F[i][j]<< " ";
        cout<< endl;
    }
    */
    cout<< F[k][n];
    return 0;
}
