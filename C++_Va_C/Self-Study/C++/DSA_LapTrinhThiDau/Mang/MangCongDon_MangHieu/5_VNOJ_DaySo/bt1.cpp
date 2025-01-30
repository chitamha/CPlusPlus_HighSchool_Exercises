#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 1000005
using namespace std;

ll n, A[maxn], MinL[maxn], MaxR[maxn], rPS[maxn], cnt=0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    for (ll i=1; i<=n; i++) cin>> A[i];
    for (ll i=n; i>=1; i--) rPS[i]=rPS[i+1]+A[i];
    MinL[1]=A[1];
    MaxR[n]=A[n];
    for (ll i=2; i<=n; i++) MinL[i]=min(MinL[i-1], rPS[1]-rPS[i+1]);
    for (ll i=n-1; i>=1; i--) MaxR[i]=max(MaxR[i+1], rPS[i]);
    //cout<< "rPS: "; for (ll i=1; i<=n; i++) cout<< rPS[i]<< " "; cout<< endl;
    //cout<< "MinL: "; for (ll i=1; i<=n; i++) cout<< MinL[i]<< " "; cout<< endl;
    //cout<< "MaxR: "; for (ll i=1; i<=n; i++) cout<< MaxR[i]<< " "; cout<< endl;
    for (ll i=1; i<=n; i++) if (rPS[i]+MinL[i-1]>0 && rPS[i]-MaxR[i+1]>0 && A[i]>0) cnt++;
    cout<< cnt;
    return 0;
}
