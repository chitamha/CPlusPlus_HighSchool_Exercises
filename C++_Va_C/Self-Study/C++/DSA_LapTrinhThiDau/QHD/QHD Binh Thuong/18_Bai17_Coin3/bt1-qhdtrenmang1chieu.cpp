#include <bits/stdc++.h>
#define maxn 1000006
#define MOD 1000000007
using namespace std;

int n, x;
int A[maxn];
int F[maxn];

int main(){
    cin>> n>> x;
    for (int i=1; i<=n; i++){
        cin>> A[i];
    }
    F[0]=1;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=x; j++){
            if (j>=A[i]){
                (F[j]+=F[j-A[i]])%=MOD;
            }
        }
    }
    cout<< F[x];
    return 0;
}
