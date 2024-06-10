#include <bits/stdc++.h>
#define ll long long
#define maxn 100006
using namespace std;

int n, A[maxn], B[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    for (int i=1; i<=n; i++) cin>> A[i];
    for (int i=1; i<=n; i++) cin>> B[i];
    sort(A+1, A+n+1); sort(B+1, B+n+1, greater<>());
    ll ans=1e18;
    int id1=1, id2=1;
    while (id1<=n && id2<=n){
        ans=min(ans, abs(1ll*(A[id1]+B[id2])));
        //min>=0 => Phai tien gan toi 0
        if (1ll*(A[id1]+B[id2])>0) id2++;
        else id1++;
    }
    cout<< ans;
    return 0;
}