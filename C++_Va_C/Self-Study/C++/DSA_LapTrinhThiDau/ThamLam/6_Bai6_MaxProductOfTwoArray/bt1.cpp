#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, sum=0;
    cin>> n;
    int A[n], B[n];
    for (int i=0; i<n; i++) cin>> A[i];
    for (int i=0; i<n; i++) cin>> B[i];
    sort(A, A+n); sort(B, B+n);
    for (int i=0; i<n; i++) sum+=A[i]*B[i];
    cout<< sum;
    return 0;
}
