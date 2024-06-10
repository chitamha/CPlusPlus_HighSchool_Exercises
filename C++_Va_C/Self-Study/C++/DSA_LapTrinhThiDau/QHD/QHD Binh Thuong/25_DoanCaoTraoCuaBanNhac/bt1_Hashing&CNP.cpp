#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 5005
#define base 88
using namespace std;

int n, A[maxn];
ll hashA[maxn], Pow[maxn];
ll MOD=1000000007;

void in1(int i, int length, int Mang[]){
    cout<< endl;
    for (int k=i; k<=length; k++)
        cout<< Mang[k]<< " ";
    cout<< endl;
}

void in2(int i, int length, ll Mang[]){
    cout<< endl;
    for (int k=i; k<=length; k++)
        cout<< Mang[k]<< " ";
    cout<< endl;
}

ll getHash(int l, int r){
    ll ans=(hashA[r]-hashA[l-1]*Pow[r-l+1]+MOD*MOD)%MOD;
    return ans;
}

bool solution(int length){
    map<ll, int> mp;
    for (int i=1; i<=n-1-length+1; i++){
        mp[getHash(i, i+length-1)]++;
    }
    for (auto x:mp){
        if (x.se>=2)
            return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>> n;
    int Min=0;
    for (int i=1; i<=n; i++) cin>> A[i];
    for (int i=1; i<=n-1; i++){
        A[i]=A[i+1]-A[i];
        Min=min(Min, A[i]);
    }
    Pow[0]=1;
    A[n]=0;
    for (int i=1; i<=n-1; i++){
        A[i]=A[i]-Min+1;
        Pow[i]=Pow[i-1]*base%MOD;
    }
    for (int i=1; i<=n-1; i++) hashA[i]=(hashA[i-1]*base+A[i])%MOD;
    int l=4, r=n-1, ans=0;
    while (l<=r){
        int mid=(l+r)/2;
        if (solution(mid)){
            ans=max(ans, mid);
            l=mid+1;
        } else r=mid-1;
    }
    if (ans) cout<< ans+1;
    else cout<< ans;
    return 0;
}
