#include <bits/stdc++.h>
using namespace std;

long long n, S, sum=0, cnt=0, ans=0;
vector<long long> A;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>> n>> S;
    A.resize(n+1);
    for (long long i=1; i<=n; i++) cin>> A[i];
    long long l=1, r=1;
    for (l; l<=n; l++){
        while ((sum+A[r]<=S) && (r<=n)){
            cnt++;
            sum+=A[r];
            r++;
        }
        if (sum<=S) ans+=cnt;
        cnt--;
        sum-=A[l];
    }
    cout<< ans;
    return 0;
}
