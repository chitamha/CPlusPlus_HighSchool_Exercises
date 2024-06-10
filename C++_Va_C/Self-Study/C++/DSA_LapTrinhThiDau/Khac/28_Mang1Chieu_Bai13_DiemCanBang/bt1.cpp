#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>> t;
    while (t--){
        int n, sum=0;
        bool check=false;
        cin>> n;
        int A[n];
        for (int i=0; i<n; i++){
            cin>> A[i];
            sum+=A[i];
        }
        int left=A[0];
        for (int i=1; i<n-1; i++){
            sum-=A[i-1];
            left+=A[i];
            if (left==sum){
                cout<< i<< endl;
                check=true;
            }
        }
        if (!check) cout<< -1<< endl;
    }
    return 0;
}
