#include <bits/stdc++.h>
#define maxn 1000006
using namespace std;
using ll=long long;

ll n;
ll A[100], NP[100], ans=1e9;
bool check=false;

void sinh(){
    ll i=n;
    while (i>=1 && NP[i]){
        NP[i]=0;
        i--;
    }
    if (i==0) check=true;
    else NP[i]=1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>> n;
    for (ll i=1; i<=n; i++) NP[i]=0;
    for (ll i=1; i<=n; i++) cin>> A[i];
    while (!check){
        ll sum1=0, sum2=0;
        for (ll i=1; i<=n; i++){
            if (NP[i]) sum1+=A[i];
            else sum2+=A[i];
        }
        ans=min(ans, abs(sum2-sum1));
        sinh();
    }
    cout<< ans;
    return 0;
}
