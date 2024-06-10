#include <bits/stdc++.h>
#define maxn 1000006
#define inf 1e9+10
#define ll long long
using namespace std;

int main(){
    freopen("CANDIES.INP", "r", stdin);
    freopen("CANDIES.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, an=0, sum=0;
    cin>> n;
    for (int i=1; i<=n; i++){
        int x; cin>> x;
        if (x%3==0 && x>=3){
            sum+=x;
            an++;
        }
    }
    cout<< an<< endl;
    cout<< sum/3-an;
    return 0;
}
