#include <bits/stdc++.h>
#define maxn 1000006
#define inf 1e9+10
#define ll long long
using namespace std;

int main(){
    freopen("ROBOT.INP", "r", stdin);
    freopen("ROBOT.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll a, b, x, y; cin>> a>> b>> x>> y;
    cout<< max(abs(a-x), abs(b-y));
    return 0;
}
