#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, cnt=0;
vector<ll> v;

void Count(ll post, ll sum){
    ll left=post+1, right=n-1;
    while (left<right){
        if (v[left]+v[right]==sum){
            cnt++;
            left++; right--;
        } else if(v[left]+v[right]<sum) left++;
        else right--;
    }
}

int main(){
    freopen("ZEROSUM.INP", "r", stdin);
    freopen("ZEROSUM.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>> n;
    v.resize(n);
    for (ll i=0; i<n; i++) cin>> v[i];
    sort(v.begin(), v.end());
    for (ll i=0; i<n; i++){
        Count(i, -v[i]);
    }
    cout<< cnt;
    return 0;
}
