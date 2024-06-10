#include <bits/stdc++.h>
#define maxn 1000006
#define inf 1e9+10
#define ll long long
using namespace std;

int n, k; ll sum1=0, sum2=0, ans=0;
vector<ll> A, Min, Max;

int main(){
    freopen("DAXANH.INP", "r", stdin);
    freopen("DAXANH.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> k;
    A.resize(n+1); Min.resize(n+1); Max.resize(n+1);
    for (int i=1; i<=n; i++){
        cin>> A[i];
        if (i>k && i<2*k) sum1+=A[i];
        if (i<=k) sum2+=A[i];
    }
    Min[k]=Max[k]=sum2;
    for (int i=k+1; i<=n; i++){
        if (i>=2*k){
            sum1=sum1+A[i];
            if (i-k>=k+1) sum1-=A[i-k];
            ans=max({ans, abs(sum1-Min[i-k]), abs(sum1-Max[i-k])});
        }
        sum2+=A[i]-A[i-k];
        Min[i]=min(Min[i-1], sum2);
        Max[i]=max(Max[i-1], sum2);
    }
    cout<< ans;
    return 0;
}
