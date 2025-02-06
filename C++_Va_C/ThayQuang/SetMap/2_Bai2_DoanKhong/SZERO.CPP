#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

int n, l=0, r=0;
ll sum=0;
map<ll, int> mp;

int main(){
    freopen("SZERO.INP", "r", stdin);
    freopen("SZERO.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    mp[0]=0;
    for (int i=1; i<=n; i++){
        int x; cin>> x;
        sum+=x;
        if (mp.count(sum)==0) mp[sum]=i;
        else {
            if (i-mp[sum]>=r-l+1){
                l=mp[sum]+1;
                r=i;
            }
        }
    }
    cout<< l<< " "<< r;
    return 0;
}
