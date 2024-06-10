#include <bits/stdc++.h>
#define ll long long
#define maxn 1000006
using namespace std;

ll n, Plus[maxn], Sub[maxn], A[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    for (ll i=1; i<=n; i++) cin>> A[i];
    Plus[1]=A[1]; Sub[1]=0;
    for (ll i=2; i<=n; i++){
        Plus[i]=max(Plus[i-1], Sub[i-1]+A[i]);
        Sub[i]=max(Sub[i-1], Plus[i-1]-A[i]);
    }
    cout<< max(Plus[n], Sub[n]);
    return 0;
}
