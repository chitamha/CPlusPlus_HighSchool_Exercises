#include <bits/stdc++.h>
using namespace std;

long long n, sum=0, gt=1, mod=20240131;

int main(){
    freopen("FACTORIAL.INP", "r", stdin);
    freopen("FACTORIAL.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    /*
    20240131=83*243857
    Vì thế những số >= 243857 thì giai thừa của nó chứa 83 và 243857
    nên khi mod với 20240131 thì có kết quả là 0
    */
    for (long long i=1; i<=min(n, 1ll*243856); i++){
        gt=(gt*i)%mod;
        sum=(sum+gt)%mod;
    }
    cout<< sum;
    return 0;
}
