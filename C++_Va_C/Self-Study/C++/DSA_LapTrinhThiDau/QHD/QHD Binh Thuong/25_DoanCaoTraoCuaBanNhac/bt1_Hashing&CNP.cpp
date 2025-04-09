#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 5005
#define base 90
using namespace std;

ll n, A[maxn], hashA[maxn], Pow[maxn], MOD=1000000007;

ll getHash(int l, int r){
    return (hashA[r]-hashA[l-1]*Pow[r-l+1]+MOD*MOD)%MOD;
}

int checkLen(int len){
    map<ll, int> mp;
    for (int i=1; i<=n-len; i++){
        ll tmp=getHash(i, i+len-1);
        if (mp.count(tmp)!=0 && i>mp[tmp]) return 1;
        if (mp.count(tmp)==0) mp[tmp]=i+len;
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>> n;
    ll Min=-1e9;
    for (int i=1; i<=n; i++) cin>> A[i];
    for (int i=1; i<=n-1; i++){
        A[i]=A[i+1]-A[i];
        Min=min(Min, A[i]);
    }
    A[n]=0;
    Pow[0]=1;
    for (int i=1; i<=n-1; i++){
        A[i]=A[i]-Min+1;
        Pow[i]=(Pow[i-1]*base)%MOD;
    }
    for (int i=1; i<=n-1; i++) hashA[i]=(hashA[i-1]*base+A[i])%MOD;
    int l=4, r=n-1, mid, check=0;
    while (l<=r){
        mid=(l+r)/2;
        if (checkLen(mid)) l=mid+1, check=1;
        else r=mid-1;
    }
    if (check) cout<< l;
    else cout<< 0;
    return 0;
}
