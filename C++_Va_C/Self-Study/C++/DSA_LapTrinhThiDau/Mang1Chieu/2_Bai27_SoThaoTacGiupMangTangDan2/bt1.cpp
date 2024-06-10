#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, d, dem=0;
    cin>> n>> d;
    int A[n];
    for (int i=0; i<n; i++) cin>> A[i];
    for (int i=1; i<n; i++){
        while (A[i]<=A[i-1]){
            dem++;
            A[i]=A[i]+d;
        }
    }
    cout<< dem;
    return 0;
}
