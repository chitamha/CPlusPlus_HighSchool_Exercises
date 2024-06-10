#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll n, k, ans, sum=0;

bool check(ll mid, ll k, ll n, ll A[]){
    ll sum=0, cnt=0;
    for (ll i=0; i<n; i++){
        sum+=A[i];
        if (sum>mid){
            cnt++;
            sum=A[i];
        }
    }
    cnt++;
    return cnt<=k;
}

int main(){
    cin>> n>> k;
    ll A[n];
    for (ll i=0; i<n; i++){
        cin>> A[i];
        sum+=A[i];
    }
    ll left=*max_element(A, A+n), right=sum;
    while (left<=right){
        ll mid=(left+right)/2;
        if (check(mid, k, n, A)){
            ans=mid;
            right=mid-1;
        } else left=mid+1;
    }
    cout<< ans;
    return 0;
}
