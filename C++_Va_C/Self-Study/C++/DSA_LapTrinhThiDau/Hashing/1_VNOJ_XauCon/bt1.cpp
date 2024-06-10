#include <bits/stdc++.h>
#define ll long long
#define maxn 1000006
#define base 31
//#define MOD 1000000007
using namespace std;

ll n, m, hashB;
ll F[maxn], Pow[maxn];
ll MOD=1000000007;
string A, B;

ll getHash(int l, int r){
    ll ans=(F[r]-F[l-1]*Pow[r-l+1]+MOD*MOD)%MOD;
    //ll ans=((F[r]-F[l-1]*Pow[r-l+1])%MOD+MOD)%MOD;
    return ans;
}

int main(){
    cin>> A>> B;
    n=A.size(), m=B.size();
    A=' '+A; B=' '+B;
    //Hashing
    Pow[0]=1;
    for (int i=1; i<=m; i++) Pow[i]=(Pow[i-1]*base)%MOD;
    for (int i=1; i<=m; i++) hashB=(hashB*base+B[i]-'a'+1)%MOD;
    for (int i=1; i<=n; i++) F[i]=(F[i-1]*base+A[i]-'a'+1)%MOD;
    //cout<< hashB<< endl;
    for (int i=1; i<=n-m+1; i++){
        //cout<< getHash(i, i+m-1)<< " ";
        if (hashB==getHash(i, i+m-1)) cout<< i<< " ";
    }
    return 0;
}
