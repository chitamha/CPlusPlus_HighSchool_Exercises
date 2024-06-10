#include <bits/stdc++.h>
#define ll long long
#define maxn 1000006
#define base 31
//#define MOD 1000000007
using namespace std;

ll n, m, hashA[maxn], hashB[maxn], Pow[maxn];
ll MOD=1000000007;
string A, B;

ll getHash(int l, int r, long long F[]){
    ll ans=(F[r]-F[l-1]*Pow[r-l+1]+MOD*MOD)%MOD;
    //ll ans=((F[r]-F[l-1]*Pow[r-l+1])%MOD+MOD)%MOD;
    return ans;
}

int main(){
    cin>> A>> B;
    n=A.size(); m=B.size();
    A=' '+A; B=' '+B;
    //Hashing
    Pow[0]=1;
    for (int i=1; i<=max(n, m); i++) Pow[i]=(Pow[i-1]*base)%MOD;
    for (int i=1; i<=n; i++) hashA[i]=(hashA[i-1]*base+A[i]-'a'+1)%MOD;
    for (int i=1; i<=m; i++) hashB[i]=(hashB[i-1]*base+B[i]-'a'+1)%MOD;
    for (int i=min(n, m); i>=1; i--){
        if (getHash(n-i+1, n, hashA)==getHash(1, i, hashB)){
            for (int j=1; j<=n; j++)
                cout<< A[j];
            for (int j=i+1; j<=m; j++)
                cout<< B[j];
            return 0;
        }
    }
    cout<< A<< B;
    return 0;
}
/*
Input:
abca
cab
Output:
abcab
*/
