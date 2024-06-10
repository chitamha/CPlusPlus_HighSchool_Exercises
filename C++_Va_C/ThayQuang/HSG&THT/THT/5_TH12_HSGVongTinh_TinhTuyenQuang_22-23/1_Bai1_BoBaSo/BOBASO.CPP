#include <bits/stdc++.h>
#define maxn 1000006
#define inf 1e9+10
#define ll long long
using namespace std;

int n; ll ans=-1e18;
vector<int> A, MinL, MinR, MaxL, MaxR;

void QHD(){
    MinL.resize(n+1, inf); MinR.resize(n+1, inf);
    MaxL.resize(n+1, -inf); MaxR.resize(n+1, -inf);
    MinL[1]=A[1]; MinR[n]=A[n];
    MaxL[1]=A[1]; MaxR[n]=A[n];
    for (int i=2; i<=n; i++){
        MaxL[i]=max(MaxL[i-1], A[i]);
        MinL[i]=min(MinL[i-1], A[i]);
    }
    for (int i=n-1; i>=1; i--){
        MaxR[i]=max(MaxR[i+1], A[i]);
        MinR[i]=min(MinR[i+1], A[i]);
    }
}

int main(){
    freopen("BOBASO.INP", "r", stdin);
    freopen("BOBASO.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n; A.resize(n+1);
    for (int i=1; i<=n; i++) cin>> A[i];
    QHD();
    for (int j=2; j<=n-1; j++) ans=max({ans, 2ll*A[j]+abs(1ll*MaxL[j-1]-1ll*MinR[j+1]), 2ll*A[j]+abs(1ll*MaxR[j+1]-1ll*MinL[j-1])});
    cout<< ans;
    return 0;
}
