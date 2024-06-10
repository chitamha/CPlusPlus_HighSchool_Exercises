#include <bits/stdc++.h>
#define ll long long
#define maxn 5005
#define mod 1000000007
using namespace std;

int n;
ll F[maxn];
vector<int> prime;

bool isprime(int k){
    for (int i=2; i*i<=k; i++){
        if (k%i==0) return 0;
    }
    return 1;
}

int main(){
    //freopen("ADDPRIME.INP", "r", stdin);
    //freopen("ADDPRIME.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    F[0]=1; F[1]=0;
    for (int i=2; i<=n; i++){
        if (isprime(i))
            prime.push_back(i);
    }
    for (int i=0; i<prime.size(); i++){
        for (int j=2; j<=n; j++){
            if (j-prime[i]>=0) F[j]=(F[j]%mod+F[j-prime[i]]%mod)%mod;
        }
    }
    cout<< F[n];
    return 0;
}
