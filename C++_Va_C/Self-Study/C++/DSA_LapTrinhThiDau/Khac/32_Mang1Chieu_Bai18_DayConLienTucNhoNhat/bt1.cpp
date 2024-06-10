#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll t, n, X, ans;

bool check(ll n, ll X, ll A[], ll mid){
    ll sum=0;
    for (ll i=1; i<=mid; i++)
        sum+=A[i];
    for (ll i=1; i<=n-mid+1; i++){
        if (sum>X) return true;
        sum-=A[i];
        sum+=A[i+mid];
    }
    return false;
}

int main(){
    cin>> t;
    while (t--){
        ans=-1;
        cin>> n>> X;
        ll A[n+1];
        for (ll i=1; i<=n; i++) cin>> A[i];
        ll left=1, right=n;
        while (left<=right){
            ll mid=(left+right)/2;
            if (check(n, X, A, mid)){
                ans=mid;
                right=mid-1;
            } else left=mid+1;
        }
        cout<< ans<< endl;
    }
    return 0;
}
