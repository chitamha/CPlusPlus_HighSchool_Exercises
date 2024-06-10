#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n, h, ans;
bool check(ll mid, ll h, ll n, ll L[]){
    ll dis=0;
    for (int i=0; i<n; i++){
        if (mid<L[i]) dis+=L[i]-mid;
        if (dis>=h) return true;
    }
    return false;
}
int main(){
    cin>> n>> h;
    ll L[n];
    for (ll &x:L) cin>> x;
    ll l=0, r=*max_element(L, L+n);
    while (l<=r){
        ll mid=(l+r)/2;
        if (check(mid, h, n, L)){
            ans=mid;
            l=mid+1;
        } else r=mid-1;
    }
    cout<< ans;
    return 0;
}
