#include <bits/stdc++.h>
using namespace std;
int main(){
    int testcase;
    cin>> testcase;
    while (testcase){
        int Max=-1;
        int n;
        cin>> n;
        int A[n];
        for (int i=0; i<n; i++){
            cin>> A[i];
        }
        for (int i=0; i<n-1; i++){
            for (int j=i+1; j<n; j++){
                Max=max(Max, A[j]-A[i]);
            }
        }
        if (Max>0) cout<< Max;
        else cout<< -1;
        cout<< endl;
        --testcase;
    }
}
