#include <bits/stdc++.h>
#define ll long long
#define maxn 1000006
using namespace std;

int q;
vector<ll> A(maxn);

void process(ll x){
    ll sum=1;
    for (int i=2; i<=sqrt(x); i++){
        ll tmptong=1, tich=1;
        while (x%i==0){
            tich*=i;
            tmptong+=tich;
            x/=i;
        }
        sum*=tmptong;
    }
    if (x!=1) sum*=(x+1);
    cout<< sum<< " ";
}

int main(){
    freopen("BOMCHUM.INP", "r", stdin);
    freopen("BOMCHUM.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> q;
    for (int i=1; i<=q; i++) cin>> A[i];
    for (int i=1; i<=q; i++) process(A[i]);
    return 0;
}
