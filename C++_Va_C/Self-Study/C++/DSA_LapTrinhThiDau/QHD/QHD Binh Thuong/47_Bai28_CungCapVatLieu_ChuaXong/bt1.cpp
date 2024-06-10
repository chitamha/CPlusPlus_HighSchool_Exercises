#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
using namespace std;

int n, r, D[105], A[105], B[105], F[105][10005], slmax=0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> r;
    for (int i=1; i<=n; i++){
        cin>> D[i];
        slmax=max(slmax, D[i]);
    }
    for (int i=1; i<=n; i++) cin>> A[i];
    for (int i=1; i<=n; i++) cin>> B[i];
    memset(F, 62, sizeof F);
    for (int i=0; i<=n; i++) F[i][0]=0;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=slmax; j++){
            for (int k=0; k<=min(r, j); k++){
                F[i][j]=min(F[i][j], F[i-1][D[i-1]]+k*A[i]+(j-k)*B[i]);
            }
        }
    }
    int id=D[n];
    for (int i=D[n]; i<=slmax; i++) if (F[n][id]>F[n][i]) id=i;
    cout<< F[n][id];
    return 0;
}
