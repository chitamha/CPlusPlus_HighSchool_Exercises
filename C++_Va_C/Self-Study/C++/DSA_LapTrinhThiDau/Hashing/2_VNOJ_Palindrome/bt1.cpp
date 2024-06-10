#include <bits/stdc++.h>
#define ll long long
#define maxn 1000006
#define base 31
//#define MOD 1000000007
using namespace std;

ll n, hashA[maxn], hashB[maxn], Pow[maxn];
ll MOD=1000000007;
string A, B;

ll getHash(int l, int r, long long F[]){
    ll ans=(F[r]-F[l-1]*Pow[r-l+1]+MOD*MOD)%MOD;
    //ll ans=((F[r]-F[l-1]*Pow[r-l+1])%MOD+MOD)%MOD;
    return ans;
}

int main(){
    cin>> A;
    n=A.size(); B=A;
    reverse(B.begin(), B.end());
    A=' '+A; B=' '+B;
    //Hashing
    Pow[0]=1;
    for (int i=1; i<=n; i++) Pow[i]=(Pow[i-1]*base)%MOD;
    for (int i=1; i<=n; i++) hashA[i]=(hashA[i-1]*base+A[i]-'a'+1)%MOD;
    for (int i=1; i<=n; i++) hashB[i]=(hashB[i-1]*base+B[i]-'a'+1)%MOD;
    int t; cin>> t;
    while (t--){
        int l, r;
        cin>> l>> r;
        if (getHash(l, r, hashA)==getHash(n-r+1, n-l+1, hashB))
            cout<< "YES"<< endl;
        else cout<< "NO"<< endl;
    }
    return 0;
}
/*
Input:
abbacaba
5
1 2
6 8
1 1
1 4
4 6
Output:
NO
YES
YES
YES
YES
*/
