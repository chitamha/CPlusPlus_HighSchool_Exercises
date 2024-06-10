#include <bits/stdc++.h>
#define maxn 1000001
#define MOD 1000000007
using namespace std;

int n, x, A[maxn];
vector<int> F(maxn, 0);

int main(){
    cin>> n>> x;
    for (int i=1; i<=n; i++) {
        cin>> A[i];
    }
    F[0]=1;
    for (int j=1; j<=n; j++){
        for (int i=1; i<=x; i++){
            if (i-A[j]>=0){
                (F[i]+=F[i-A[j]])%=MOD;
            }
        }
    }
    cout<< F[x];
}
