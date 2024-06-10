#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, k, ans=0, cnt=0;
ll DD[100005];
vector<ll> v;

void in(ll left, ll right){
    while (right-left+1!=0){
        for (ll i=left; i<=right; i++)
            cout<< v[i]<< " ";
        cout<< endl;
        left++;
    }
}


int main(){
    freopen("COUNT.INP", "r", stdin);
    freopen("COUNT.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>> n>> k;
    v.resize(n+1);
    for (ll i=1; i<=n; i++) cin>> v[i];
    ll left=1, right=1;
    while (right<=n){
        if (DD[v[right]]==0){
            DD[v[right]]++;
            cnt++;
        } else DD[v[right]]++;
        while (cnt>k && left<=right){
            if (DD[v[left]]==1){
                DD[v[left]]--;
                cnt--;
            } else DD[v[left]]--;
            left++;
        }
        ans+=right-left+1;
        in(left, right);
        right++;
    }
    cout<< ans;
    return 0;
}
