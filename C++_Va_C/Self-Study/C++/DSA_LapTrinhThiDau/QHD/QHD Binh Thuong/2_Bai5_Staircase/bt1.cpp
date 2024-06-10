#include <bits/stdc++.h>
#define maxn 100002
#define MOD 1000000007
using namespace std;

long long n, k;
vector<long long> F(maxn, 0);

int main(){
    cin>> n>> k;
    F[0]=1;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=k; j++){
            if (i-j>=0){
                F[i]+=F[i-j];
                F[i]%=MOD;
            }
        }
    }
    cout<< F[n];
}
