#include <bits/stdc++.h>
#define maxn 1000006
using namespace std;
using ll=long long;

ll n, m, ans;

bool check(ll Min, ll A[], ll n, ll m){
    ll cnt=1;
    auto it=A;
    ll value=*it;
    while (it<A+n){
        it=lower_bound(A, A+n, value+Min);
        if (it<A+n) cnt++;
        value=*it;
    }
    return cnt>=m;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>> n>> m;
    ll A[n];
    for (int i=0; i<n; i++) cin>> A[i];
    sort(A, A+n);
    ll left=0, right=A[n-1]-A[0];
    while (left<=right){
        ll mid=(left+right)/2;
        if (check(mid, A, n, m)){
            ans=mid;
            left=mid+1;
        } else right=mid-1;
    }
    cout<< ans;
    return 0;
}
