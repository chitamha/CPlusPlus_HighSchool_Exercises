#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 1006
using namespace std;

int n, m, C[maxn][maxn], F[maxn][maxn], Sl[maxn], ans=1e9;
pair<int, int> before[maxn][maxn];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m;
    memset(F, 62, sizeof F);
    for (int j=0; j<=m; j++) F[0][j]=0;
    for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) cin>> C[i][j];
    for (int j=1; j<=m; j++){
        for (int i=1; i<=n; i++){
            for (int k=0; k<=i; k++){
                if (F[i][j]>F[i-k][j-1]+C[k][j]){
                    F[i][j]=F[i-k][j-1]+C[k][j];
                    before[i][j]={i-k, j-1};
                }
            }
        }
    }
    int idMin=0;
    for (int j=1; j<=m; j++)
        if (F[n][idMin]>F[n][j]) idMin=j;
    cout<< F[n][idMin]<< endl;
    int tmp=n;
    while (idMin>0){
        Sl[idMin]=tmp-(before[tmp][idMin].fi);
        idMin--;
        tmp-=Sl[idMin+1];
    }
    for (int j=1; j<=m; j++) cout<< Sl[j]<< endl;
    return 0;
}
