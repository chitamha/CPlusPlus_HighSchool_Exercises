#include <bits/stdc++.h>
#define maxn 1000006
#define inf 1e9+10
#define ll long long
using namespace std;

int main(){
    freopen("EQLARRAY.INP", "r", stdin);
    freopen("EQLARRAY.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t, n, k, ma; ll sum;
    cin>> t;
    while (t--){
        ma=sum=0;
        cin>> n>> k;
        for (int i=1; i<=n; i++){
            int x; cin>> x;
            sum+=1ll*x;
            ma=max(x, ma);
        }
        if (ma<=sum/k && sum%k==0) cout<< "YES"<< "\n";
        else cout<< "NO"<< "\n";
    }
    return 0;
}
