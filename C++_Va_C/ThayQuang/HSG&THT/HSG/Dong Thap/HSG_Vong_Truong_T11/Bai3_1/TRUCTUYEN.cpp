#include <bits/stdc++.h>
using namespace std;

long long n, k, cnt=1e9, sum=0;
vector<long long> A;

int main(){
    freopen("TRUCTUYEN.INP", "r", stdin);
    freopen("TRUCTUYEN.OUT", "w", stdout);
    cin>> n>> k;
    A.resize(n+1);
    for (long long i=1; i<=n; i++) cin>> A[i];
    long long l=1, r=1, dem=0;
    for (l; l<=n; l++){
        for (r; r<=n; r++){
            if (sum<k){
                dem++;
                sum+=A[r];
            } else break;
        }
        if (sum>=k){
            cnt=min(cnt, dem);
        }
        sum-=A[l];
        dem--;
    }
    if (cnt!=1e9)
        cout<< cnt;
    else cout<< -1;
    return 0;
}
