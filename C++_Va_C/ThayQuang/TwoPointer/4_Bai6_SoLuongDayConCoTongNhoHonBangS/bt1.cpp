#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, s, ans=0;
vector<ll> v;

int main(){
    freopen("DAYCON.INP", "r", stdin);
    freopen("DAYCON.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>> n>> s;
    v.resize(n+1);
    for (ll i=1; i<=n; i++) cin>> v[i];
    ll left=1, right=1;
    ll sum=0;
    while (right<=n){
        sum+=v[right];
        while (sum>s && left<=right){
            sum-=v[left];
            left++;
        }
        ans+=right-left+1;
        right++;
    }
    cout<< ans;
    return 0;
}
