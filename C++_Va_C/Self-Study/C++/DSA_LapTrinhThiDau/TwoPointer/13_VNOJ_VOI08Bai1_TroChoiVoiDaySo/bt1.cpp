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
    sort(A+1, A+n+1); sort(B+1, B+n+1);
    //Tim phan tu dau tien >= -x
    //Tim phan tu cuoi cung <= -x <=> Tim phan tu dau tien > -x
    ll ans=1e18;
    for (int i=1; i<=n; i++){
        int id1=upper_bound(B+1, B+n+1, -A[i])-B-1;
        int id2=lower_bound(B+1, B+n+1, -A[i])-B;
        if (id1>=1 && id1<=n) ans=min(ans, 1ll*abs(A[i]+B[id1]));
        if (id2>=1 && id2<=n) ans=min(ans, 1ll*abs(A[i]+B[id2]));
    }
    cout<< ans;
    return 0;
}