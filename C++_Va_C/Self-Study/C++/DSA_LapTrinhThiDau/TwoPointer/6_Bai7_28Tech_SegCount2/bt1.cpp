#include <bits/stdc++.h>
using namespace std;

int n, S, sum=0, cnt=0, ans=0;
vector<int> A;

int main(){
    cin>> n>> S;
    A.resize(n+1);
    for (int i=1; i<=n; i++) cin>> A[i];
    int l=1, r=1;
    for (l; l<=n; l++){
        while (sum<S && r<=n){
            sum+=A[r];
            r++;
            cnt++;
        }
        if (sum>=S) ans+=n-cnt-1;
        sum-=A[l];
        cnt--;
    }
    cout<< ans;
    return 0;
}
