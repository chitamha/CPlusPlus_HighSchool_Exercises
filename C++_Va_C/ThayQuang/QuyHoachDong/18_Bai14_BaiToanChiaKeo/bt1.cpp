#include <bits/stdc++.h>
#define maxn 105
using namespace std;

int n, A[maxn], vet[maxn*205], F[maxn*205], sum=0;

void truyvet(int tmp){
    if (tmp==0) return;
    truyvet(tmp-A[vet[tmp]]);
    cout<< vet[tmp]<< " ";
}

int main(){
    //freopen("CHIAKEO.INP", "r", stdin);
    //freopen("CHIAKEO.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    for (int i=1; i<=n; i++){
        cin>> A[i];
        sum+=A[i];
    }
    F[0]=1;
    int ma=0;
    for (int i=1; i<=n; i++){
        for (int s=sum/2; s>=A[i]; s--){
            if (F[s-A[i]]==1 && F[s]==0){
                F[s]=1;
                vet[s]=i;
                ma=max(ma, s);
            }
        }
    }
    //cout<< ma<< endl;
    cout<< sum-2*ma<< endl;
    /*
    for (int i=1; i<=sum/2; i++) cout<< vet[i]<< " ";
    cout<< endl;
    */
    truyvet(ma);
    return 0;
}
