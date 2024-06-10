#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>> n;
    int A[n+1];
    for (int i=1; i<=n; i++) cin>> A[i];
    int cnt=1, ans=1;
    for (int i=2; i<=n; i++){
        if (A[i]==A[i-1]) cnt++;
        else cnt=1;
        ans=max(ans, cnt);
    }
    cout<< n-ans;
    return 0;
}
