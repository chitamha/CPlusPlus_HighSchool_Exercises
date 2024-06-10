#include <bits/stdc++.h>
using namespace std;

int n, S, sum, ans=0;
vector<int> A;

int main(){
    cin>> n>> S;
    A.resize(n+1);
    for (int i=1; i<=n; i++) cin>> A[i];
    A[0]=0;
    for (int i=1; i<=n; i++){
        A[i]+=A[i-1];
    }
    int r=1;
    for (int i=1; i<=n; i++){
        while (sum<S && r<=n){
            sum=A[r]-A[i-1];
            r++;
        }
        if (sum>=S){
            ans+=n-r+2;
        }
        sum=A[r-1]-A[i];
    }
    cout<< ans;
    return 0;
}
