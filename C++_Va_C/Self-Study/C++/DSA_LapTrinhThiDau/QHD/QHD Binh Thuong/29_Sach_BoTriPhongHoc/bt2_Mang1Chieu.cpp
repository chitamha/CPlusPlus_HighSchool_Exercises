#include <bits/stdc++.h>
#define maxn 10006
using namespace std;

int n, k;
int ph[maxn], hs[maxn], F[maxn];

int main(){
    cin>> n>> k;
    for (int i=1; i<=n; i++) cin>> ph[i];
    for (int i=1; i<=k; i++) cin>> hs[i];
    if (n==k){
        int sum=0;
        for (int i=1; i<=n; i++) sum+=abs(hs[i]-ph[i]);
        return cout<< sum, 0;
    }
    memset(F, 62, sizeof F);
    F[1]=abs(hs[1]-ph[1]);
    for (int j=1; j<=n; j++){
        for (int i=min(j, k); i>=1; i--){
            F[i]=min(F[i], F[i-1]+abs(hs[i]-ph[j]));
        }
    }
    cout<< F[k];
    return 0;
}
