#include <bits/stdc++.h>
#define ll long long
#define maxn 1000006
#define base 31
//#define MOD 1000000007
using namespace std;

ll n, k, hashA[maxn], Pow[maxn];
ll MOD=1000000007;
string A;

ll getHash(int l, int r, long long F[]){
    ll ans=(F[r]-F[l-1]*Pow[r-l+1]+MOD*MOD)%MOD;
    //ll ans=((F[r]-F[l-1]*Pow[r-l+1])%MOD+MOD)%MOD;
    return ans;
}

bool solution(int length){
    map<ll, ll> mp;
    for (int i=1; i<=n-length+1; i++){
        ll tmp=getHash(i, i+length-1, hashA);
        mp[tmp]++;
    }
    for (auto x:mp){
        if (x.second>=k)
            return true;
    }
    return false;
}

int main(){
    cin>> n>> k;
    cin.ignore();
    cin>> A;
    n=A.size(); A=' '+A;
    //Hashing
    Pow[0]=1;
    for (int i=1; i<=n; i++) Pow[i]=(Pow[i-1]*base)%MOD;
    for (int i=1; i<=n; i++) hashA[i]=(hashA[i-1]*base+A[i]-'a'+1)%MOD;
    int l=1, r=n, ans=0;
    while (l<=r){
        int mid=(l+r)/2;
        if (solution(mid)){
            ans=max(ans, mid);
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<< ans;
    return 0;
}
