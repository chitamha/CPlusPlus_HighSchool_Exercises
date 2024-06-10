#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, cnt=0;
vector<ll> v;

void Count(ll post, ll sum){
    ll left=0, right=n-1;
    while (left<right){
        if (v[left]==v[post]) left++;
        if (v[right]==v[post]) right--;
        //tăng left hoặc giảm right khi v[...]==v[post] có thể khiến left=right
        if (v[left]+v[right]==sum && left!=right){
            //cout<< cnt+1<< ": "<< v[left]<< " + "<< v[right]<< " = "<< sum<< endl;
            cnt++;
            left++; right--;
        } else if(v[left]+v[right]<sum) left++;
        else right--;
    }
}

int main(){
    freopen("TRIPLET.INP", "r", stdin);
    freopen("TRIPLET.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>> n;
    v.resize(n);
    for (ll i=0; i<n; i++) cin>> v[i];
    sort(v.begin(), v.end());
    for (ll i=0; i<n; i++){
        Count(i, v[i]);
    }
    cout<< cnt;
    return 0;
}
