#include <bits/stdc++.h>
#define ll long long
using namespace std;

int m, n;
ll tich=1;

int main(){
    freopen("CHUSO.INP", "r", stdin);
    freopen("CHUSO.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> m>> n;
    for (int i=1; i<=n; i++) tich=(tich*(m%10))%10;
    cout<< tich;
    return 0;
}
