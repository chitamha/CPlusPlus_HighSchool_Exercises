#include <bits/stdc++.h>
using namespace std;

long long n, S, sum=0, cnt=1e9;
vector<long long> A;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>> n>> S;
    A.resize(n+1);
    for (long long i=1; i<=n; i++) cin>> A[i];
    long long l=1, r=1;
    for (l; l<=n; l++){
        while (r<=n && sum<S){
            sum+=A[r];
            r++;
        }
        if (sum>=S) cnt=min(cnt, r-l);
        sum-=A[l];
    }
    if (cnt!=1e9)
        cout<< cnt;
    else cout<< -1;
    return 0;
}
