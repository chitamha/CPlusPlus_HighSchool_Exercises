#include <bits/stdc++.h>
#define maxn 1000006
using namespace std;

int n, A[maxn];

int main(){
    freopen("TONGMAX.INP", "r", stdin);
    freopen("TONGMAX.OUT", "w", stdout);
    cin>> n;
    for (int i=1; i<=n; i++){
        cin>> A[i];
    }
    int Max=-1e9;
    for (int i=1; i<=n; i++){
        int sum=0;
        for (int k=1; k<=i; k++){
            sum+=A[k];
        }
        for (int j=i+1; j<=n; j++){
            sum+=A[j]-A[j-i];
            Max=max(Max, sum);
        }
    }
    cout<< Max;
}
