#include <bits/stdc++.h>
using namespace std;
int main(){
    int testcase;
    cin>> testcase;
    while (testcase){
        int n;
        cin>> n;
        int A[n], B[n];
        for (int i=0; i<n; i++){
            cin>> A[i];
            B[i]=A[i];
        }
        sort(B, B+n);
        for (int i=0; i<n; i++){
            auto contro=upper_bound(B, B+n, A[i]);
            int k=contro-B;
            if (k==n) cout<< "_ ";
            else cout<< B[k]<< " ";
        }
        --testcase;
    }
}
