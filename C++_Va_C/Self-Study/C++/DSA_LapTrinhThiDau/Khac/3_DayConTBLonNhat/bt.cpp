#include <bits/stdc++.h>
using namespace std;
int main(){
    int testcase;
    cin>> testcase;
    while (testcase){
        int tb=-1e9;
        int n, k, res=-1;
        cin>> n>> k;
        int A[n];
        for (int i=0; i<n; i++){
            cin>> A[i];
        }
        for (int i=0; i<=n-k; i++){
            int tong=0;
            for (int j=i; j<k+i; j++){
                tong+=A[j];
            }
            if (tb<tong/k){
                tb=tong/k;
                res=i;
            }
        }
        for (int i=res; i<res+k; i++){
            cout<< A[i]<< " ";
        }
        --testcase;
    }
}
