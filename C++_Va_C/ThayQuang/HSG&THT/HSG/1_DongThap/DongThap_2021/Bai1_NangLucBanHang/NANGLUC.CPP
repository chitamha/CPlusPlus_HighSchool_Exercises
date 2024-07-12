#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 100006
using namespace std;

int n, k, A[maxn];

int main(){
    freopen("NANGLUC.INP", "r", stdin);
    freopen("NANGLUC.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> k;
    for (int i=1; i<=n; i++) cin>> A[i];
    int l=1, r=1, sum=0, ma=0;
    while (r<=n){
        sum+=A[r];
        while (sum>=k && l<=r){
            ma=max(ma, sum/(r-l+1));
            sum-=A[l];
            l++;
        }
        r++;
    }
    cout<< ma;
    return 0;
}
