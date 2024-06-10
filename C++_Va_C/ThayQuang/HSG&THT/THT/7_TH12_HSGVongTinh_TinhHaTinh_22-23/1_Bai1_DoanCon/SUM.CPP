#include <bits/stdc++.h>
#define maxn 100006
#define fi first
#define se second
#define ll long long
using namespace std;

int n;
ll sum=0, cnt=0;

int main(){
    freopen("SUM.INP", "r", stdin);
    freopen("SUM.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    map<ll, ll> mp;
    for (int i=1; i<=n; i++){
        int x; cin>> x;
        sum+=x;
        if (sum==0) cnt++;
        if (mp.count(sum)!=0) cnt+=mp[sum];
        mp[sum]++;
    }
    cout<< cnt;
    return 0;
}
