#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 3000006
using namespace std;

int main(){
    freopen("SOMAYMAN.INP", "r", stdin);
    freopen("SOMAYMAN.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, t; map<int, int> mp;
    cin>> n>> t;
    for (int i=1; i<=n; i++){
        int x; cin>> x;
        mp[x]++;
    }
    while (t--){
        int x; cin>> x;
        cout<< mp[x]<< endl;
    }
    return 0;
}
