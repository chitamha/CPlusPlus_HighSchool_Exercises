#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, s, ans=1e9;
vector<ll> v;

int main(){
    freopen("MIN.INP", "r", stdin);
    freopen("MIN.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>> n>> s;
    v.resize(n+1);
    for (ll i=1; i<=n; i++) cin>> v[i];
    ll left=1, right=1;
    ll sum=0;
    while (right<=n){
        sum+=v[right];
        while (sum>=s && left<=right){
            ans=min(ans, right-left+1);
            sum-=v[left];
            left++;
        }
        right++;
    }
    if (ans!=1e9) cout<< ans;
    else cout<< -1;
    return 0;
}
