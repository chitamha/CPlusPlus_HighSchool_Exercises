#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>> n;
    int A[n+1], F[n+1];
    for (int i=1; i<=n; i++) cin>> A[i];
    for (int i=1; i<=n; i++){
        F[i]=1;
        for (int j=1; j<i; j++){
            if (A[j]<A[i]){
                F[i]=max(F[i], F[j]+1);
            }
        }
    }
    cout<< n-*max_element(F+1, F+n+1);
    return 0;
}
