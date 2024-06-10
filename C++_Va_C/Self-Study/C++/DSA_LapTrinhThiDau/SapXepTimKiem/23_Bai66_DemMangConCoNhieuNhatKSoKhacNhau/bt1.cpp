#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll n, k, ans=0;
map<ll, ll> mp;

int main(){
    cin>> n>> k;
    ll A[n];
    for (ll &x:A) cin>> x;
    ll left=0, right=0;
    while (right<n){
        mp[A[right]]++;
        while (mp.size()>k){
            if (mp[A[left]]==1){
                mp.erase(A[left]);
            } else mp[A[left]]--;
            left++;
        }
        ans+=right-left+1;
        right++;
    }
    cout<< ans;
    return 0;
}
