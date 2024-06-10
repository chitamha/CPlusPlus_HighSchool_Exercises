#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 10006
using namespace std;

int n, m, D[maxn], F[maxn][506];

int main(){
    //freopen("text1.inp", "r", stdin);
    //freopen("text1.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m;
    for (int i=1; i<=n; i++) cin>> D[i];
    for (int i=1; i<=n; i++){
        for (int j=m; j>=0; j--){
            if (j!=m) F[i][j]=F[i-1][j+1]+D[i];
            else F[i][j]=F[i-1][j];
            int u=i, v=j;
            while (j==m){
                u--; v--;
                if (u>=0 && v>=0) F[i][j]=max(F[i][j], F[u][v]);
                else break;
            }
        }
    }
    /*
    for (int i=0; i<=n; i++){
        for (int j=0; j<=m; j++) cout<< F[i][j]<< " ";
        cout<< endl;
    }
    */
    cout<< F[n][m];
    return 0;
}
