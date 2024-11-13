#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 200006
using namespace std;

ll n, ans=maxn, dif=0;
vector<ll> A;
map<int, int> mp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    A.resize(n+5);
    for (int i=1; i<=n; i++) cin>> A[i], mp[A[i]]++; {}
    dif=mp.size();
    mp.clear();
    ll l=1, r=1;
    while (r<=n){
        mp[A[r]]++;
        while (mp.size()==dif){
            ans=min(ans, r-l+1);
            if (mp[A[l]]>1) mp[A[l]]--;
            else mp.erase(A[l]);
            l++;
        }
        r++;
    }
    cout<< ans;
    return 0;
}
