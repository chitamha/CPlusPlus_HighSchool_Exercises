#include <bits/stdc++.h>
#define maxn 100005
#define MOD 14062008
using namespace std;

int n, k, F[maxn];

int main(){
    freopen("STEP.INP", "r", stdin);
    freopen("STEP.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> k;
    memset(F, -1, sizeof F);
    for (int i=1; i<=k; i++){
        int x; cin>> x;
        F[x]=0;
    }
    F[0]=0; F[1]=1;
    if (F[2]==-1) F[2]=1;
    for (int i=3; i<=n; i++){
        if (F[i]==-1){
            F[i]=(F[i-1]+F[i-2])%MOD;
        }
    }
    cout<< F[n];
    return 0;
}
