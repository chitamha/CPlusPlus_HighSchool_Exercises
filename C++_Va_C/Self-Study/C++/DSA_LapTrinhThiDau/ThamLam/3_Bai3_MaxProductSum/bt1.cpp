#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>> n;
    long long sum=0;
    long long MOD=1000000007;
    long long A[n];
    for (int i=0; i<n; i++)
        cin>> A[i];
    sort(A, A+n);
    for (int i=0; i<n; i++)
        (sum+=i*A[i]%MOD)%=MOD;
    cout<< sum;
    cout<< endl;
}
