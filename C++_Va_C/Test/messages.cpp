#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
using namespace std;

int n, m, Cost[105][105], F[105][105], before[105][105], Cast[105];

int main(){
    freopen("messages.inp", "r", stdin);
    freopen("messages.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin>> n>> m;
    for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) cin>> Cost[i][j];

    memset(F, 62, sizeof F);
    for (int j=1; j<=m; j++) F[0][j]=0;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            for (int k=0; k<=i; k++){
                if (F[i][j]>F[i-k][j-1]+Cost[k][j]){
                    F[i][j]=F[i-k][j-1]+Cost[k][j];
                    before[i][j]=k;
                }
            }
        }
    }

    cout<< F[n][m]<< endl;

    int tmp=m;
    while (n>0){
        //cout<< n<< " "<< m<< " "<< before[n][m]<< endl;
        Cast[tmp]=before[n][tmp];
        n-=before[n][tmp];
        tmp--;
    }
    for (int i=1; i<=m; i++) cout<< Cast[i]<< endl;
    return 0;
}
