#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 1000006
using namespace std;

ll n, A[maxn], maxl[maxn], maxr[maxn], ans=0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    for (int i=1; i<=n; i++){
        cin>> A[i];
        maxl[i]=maxr[i]=A[i];
    }
    for (int i=2; i<=n; i++) maxl[i]=max(maxl[i], maxl[i-1]);
    for (int i=n-1; i>=1; i--) maxr[i]=max(maxr[i], maxr[i+1]);
    for (int i=2; i<=n-1; i++) ans+=max(min(maxl[i-1], maxr[i+1])-A[i], 0ll);
    cout<< ans;
    return 0;
}
