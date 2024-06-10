#include <bits/stdc++.h>
using namespace std;

long long n;
int k, cnt=1;

int main(){
    freopen("XOASO.INP", "r", stdin);
    freopen("XOASO.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> k;
    while (n%k!=0){
        cnt++;
        long long tmp=(n/k)*k;
        n=n-((tmp-k)/k+1);
    }
    cout<< cnt;
    return 0;
}
