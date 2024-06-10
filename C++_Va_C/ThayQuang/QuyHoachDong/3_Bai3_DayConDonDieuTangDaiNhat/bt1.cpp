#include <bits/stdc++.h>
#define inf 999999999
using namespace std;

int n;
vector<int> A, truyvet, vet;
int F[1005];

int main(){
    freopen("DAYCON.INP", "r", stdin);
    freopen("DAYCON.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>> n;
    A.resize(n+2); vet.resize(n+2);
    A[0]=-inf; A[n+1]=inf;
    for (int i=1; i<=n; i++) cin>> A[i];
    F[0]=1; F[1]=2;
    for (int i=2; i<=n+1; i++){
        for (int j=1; j<i; j++){
            if (A[i]>A[j] && F[i]<=F[j]+1){
                F[i]=F[j]+1;
                vet[i]=j;
            }
        }
    }
    int i=n+1;
    while (i>0){
        truyvet.push_back(A[i]);
        i=vet[i];
    }
    cout<< F[n+1]-2<< endl;
    for (int i=truyvet.size()-1; i>=1; i--)
        cout<< truyvet[i]<< " ";
    return 0;
}
