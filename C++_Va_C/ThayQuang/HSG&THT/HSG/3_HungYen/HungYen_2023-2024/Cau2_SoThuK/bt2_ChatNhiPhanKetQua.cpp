#include <bits/stdc++.h>
#define ll unsigned long long
#define maxn 100005
using namespace std;

ll n, t, k, A[maxn];

//Số số nhỏ hơn hoặc bằng
ll Ssnhhb(ll x){
    auto it=upper_bound(A+1, A+n+1, x);
    it--;
    return it-A;
}

bool check(ll x){
    if (x<k) return false;
    ll dis=x-k;
    if (Ssnhhb(x)==dis || Ssnhhb(x)<dis) return true;
    else return false;
}

ll process(ll k){
    ll l=0, r=1e18+1e6, ans=0;
    while (r-l>=2){
        ll mid=(l+r)/2;
        if (check(mid)){
            ans=mid;
            r=mid;
        } else l=mid;
    }
    return ans;
}

int main(){
    cin>> n>> t;
    for (ll i=1; i<=n; i++) cin>> A[i];
    sort(A+1, A+n+1);
    while (t--){
        cin>> k;
        cout<< process(k)<< endl;
    }
    return 0;
}
