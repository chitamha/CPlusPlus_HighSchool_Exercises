#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, m, cnt=0;
vector<ll> v;

int main(){
    freopen("PAIR.INP", "r", stdin);
    freopen("PAIR.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>> n>> m;
    v.resize(n);
    for (ll i=0; i<n; i++) cin>> v[i];
    sort(v.begin(), v.end());
    ll left=0, right=n-1;
    while (left<right){
        if (v[left]+v[right]==m){
            cnt++;
            left++; right--;
        } else if(v[left]+v[right]<m) left++;
        else right--;
    }
    cout<< cnt;
    return 0;
}
