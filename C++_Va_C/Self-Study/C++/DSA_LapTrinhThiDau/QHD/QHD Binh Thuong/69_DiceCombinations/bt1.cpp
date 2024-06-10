#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

vector<long long> soCach(1000000, 0);
long long socach(int n){
    if (n==1 || n==0) return 1;
    if (n==2) return 2;
    if (soCach[n]!=0) return soCach[n];
    if (n<=6){
        for (int i=1; i<=n; i++){
            (soCach[n]+=socach(n-i))%=MOD;
        }
    }
    else {
        for (int i=1; i<=6; i++)
            (soCach[n]+=socach(n-i))%=MOD;
    }
    return soCach[n];
}

int main(){
    int n; cin>> n;
    cout<< socach(n);
    return 0;
}
