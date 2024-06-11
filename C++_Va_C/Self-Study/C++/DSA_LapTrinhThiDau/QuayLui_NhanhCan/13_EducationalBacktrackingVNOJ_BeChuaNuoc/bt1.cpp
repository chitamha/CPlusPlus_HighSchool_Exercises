#include <bits/stdc++.h>
using namespace std;

int n, k, ans=0;
int MaxL[15], MaxR[15], A[15], B[15], X[15];

void xuli(){
    int sum=0;
    memset(MaxL, 0, sizeof MaxL);
    memset(MaxR, 0, sizeof MaxR);
    memset(B, 0, sizeof B);
    for (int i=1; i<=k; i++) B[X[i]]++;
    for (int i=1; i<=n; i++){
        MaxL[i]=max(MaxL[i-1], B[i]+A[i]);
        MaxR[n-i+1]=max(MaxR[n-i+2], B[n-i+1]+A[n-i+1]);
    }
    for (int i=1; i<=n; i++) sum+=max(0, min(MaxL[i], MaxR[i])-B[i]-A[i]);
    ans=max(ans, sum);
}

void Try(int i){
    for (int j=1; j<=n; j++){
        X[i]=j;
        if (i==k) xuli();
        else Try(i+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> k;
    for (int i=1; i<=n; i++) cin>> A[i];
    Try(1);
    cout<< ans;
    return 0;
}
