#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> A;
int F1[1005], F2[1005];

int main(){
    //freopen("BITONIC.INP", "r", stdin);
    //freopen("BITONIC.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>> n;
    A.resize(n+1, 0);
    for (int i=1; i<=n; i++) cin>> A[i];
    for (int i=1; i<=n; i++){
        F1[i]=A[i];
        for (int j=1; j<i; j++){
            if (A[i]>A[j]) F1[i]=max(F1[i], F1[j]+A[i]);
        }
    }
    for (int i=n; i>=1; i--){
        F2[i]=A[i];
        for (int j=i+1; j<=n; j++){
            if (A[i]>A[j]) F2[i]=max(F2[i], F2[j]+A[i]);
        }
    }
    int ans=0;
    for (int i=1; i<=n; i++) ans=max(ans, F1[i]+F2[i]-A[i]);
    cout<< ans;
    return 0;
}
