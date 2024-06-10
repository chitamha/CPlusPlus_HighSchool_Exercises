#include <bits/stdc++.h>
#define maxn 10006
#define ll long long
using namespace std;

ll n, cnt=0;
int main(){
    freopen("TSNT.INP", "r", stdin);
    freopen("TSNT.OUT", "w", stdout);
    cin>> n;
    for (int i=2; i<=sqrt(n); i++){
        if (n%i==0){
            cnt++;
            while (n%i==0) n/=i;
        }
    }
    if (n!=1) cnt++;
    cout<< cnt;
    return 0;
}
