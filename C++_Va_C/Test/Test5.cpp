#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 1000006
using namespace std;

int n, A[505], S, F[505][50005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    for (int i=1; i<=n; i++) cin>> A[i];
    cin>> S;
    F[1][-A[1]+25000]=1; F[1][A[1]+25000]=1;
    int Mi=min(-A[1], A[1]), Ma=max(-A[1], A[1]);
    for (int i=2; i<=n; i++){
        int a=Mi, b=Ma;
        for (int j=a; j<=b; j++){
            if (F[i-1][j+25000]){
                F[i][j-A[i]+25000]=1;
                F[i][j+A[i]+25000]=1;
                Mi=min(Mi, j-A[i]);
                Ma=max(Ma, j+A[i]);
            }
        }
    }
    if (F[n][S+25000]) cout<< "YES";
    else cout<< "NO";
    return 0;
}
