#include <bits/stdc++.h>
#define maxn 1006
#define fi first
#define se second
#define ll long long
using namespace std;

int n, A[maxn], F[maxn][maxn];

int main(){
    //freopen("DSDB.INP", "r", stdin);
    //freopen("DSDB.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    for (int i=1; i<=n; i++) cin>> A[i];
    for (int i=0; i<=n; i++) F[i][i]=1;
    for (int i=n; i>=1; i--){
        for (int j=i+1; j<=n; j++){
            if (A[i]!=A[j]) F[i][j]=max(F[i+1][j], F[i][j-1]);
            else F[i][j]=F[i+1][j-1]+2;
        }
    }
    /*
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++) cout<< F[i][j]<< " ";
        cout<< endl;
    }
    */
    cout<< n-F[1][n];
    return 0;
}
