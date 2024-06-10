#include <bits/stdc++.h>
#define ll long long
#define maxn 300006
using namespace std;

ll n, m, A[maxn], B[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    ll sum=0;
    for (ll i=1; i<=n; i++) cin>> A[i], sum+=A[i]; {}
    cin>> m;
    for (ll i=1; i<=m; i++) cin>> B[i], sum-=B[i]; {}
    if (sum!=0) return cout<< -1, 0;
    ll len=0, pos1=1, pos2=1;
    while (pos1<=n && pos2<=m){
        len++;
        ll sum1=A[pos1++], sum2=B[pos2++];
        while (sum1!=sum2){
            if (sum1>sum2) sum2+=B[pos2++];
            else sum1+=A[pos1++];
        }
    }
    cout<< len;
    return 0;
}