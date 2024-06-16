#include <bits/stdc++.h>
#define maxn 1000006
#define ll long long
#define fi first
#define se second
using namespace std;

ll n, x;
vector<ll> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> x; v.resize(n+10);
    for (ll i=1; i<=n; i++) cin>> v[i];
    map<ll, pair<ll, ll>> mp;
/*
    Tư tưởng thuật toán: Tìm bộ 4 số (i; j; k; l) sao cho v[i]+v[j]+v[k]+v[l]=x.
    Không mất tính tổng quát, giả sử i<j<k<l.
    Thay vì 4 for thì ở vòng lặp j (vòng lặp thứ 2, ở 4 for), ta sẽ tìm 2 số k, l
    sao cho thõa mãn đã có cặp (i, j) có tổng bằng x-v[k]-v[l] từ trước.
*/
    for (ll i=1; i<=n-3; i++){
        for (ll j=i+1; j<=n-2; j++){
            if (mp.count(v[i]+v[j])==0) mp[v[i]+v[j]]={i, j};
            else{
                if (mp[v[i]+v[j]].se>j)
                    mp[v[i]+v[j]]={i, j};
            }
        }
    }
    for (ll i=3; i<=n-1; i++){
        for (ll j=i+1; j<=n; j++){
            if (mp.count(x-v[i]-v[j])!=0){
                if (mp[x-v[i]-v[j]].se<i){
                    cout<< mp[x-v[i]-v[j]].fi<< " "<< mp[x-v[i]-v[j]].se<< " "<< i<< " "<< j;
                    return 0;
                }
            }
        }
    }
    cout<< "IMPOSSIBLE";
    return 0;
}
