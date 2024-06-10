#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n, k, sum=0;
    cin>> n>> k;
    long long A[n];
    for (int i=0; i<n; i++){
        cin>> A[i];
        sum+=A[i];
    }
    sort(A, A+n);
    for (int i=0; i<min(k, n-k); i++)
        sum-=A[i]*2;
    cout<< sum;
}
