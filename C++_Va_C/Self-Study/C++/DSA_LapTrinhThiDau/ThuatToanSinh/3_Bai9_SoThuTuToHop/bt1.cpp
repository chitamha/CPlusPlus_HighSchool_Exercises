#include <bits/stdc++.h>
#define maxn 1000006
using namespace std;
using ll=long long;

ll n, k;
bool check=false;
ll A[100];
vector<vector<ll>> res;
vector<ll> v;

void sinh(){
    ll i=k;
    while (A[i]==n-k+i && i>=1){
        i--;
    }
    if (i==0) check=true;
    else{
        A[i]++;
        for (ll m=i+1; m<=n; m++){
            A[m]=A[m-1]+1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>> n>> k;
    v.resize(k);
    for (ll i=0; i<k; i++) cin>> v[i];
    for (ll i=1; i<=k; i++) A[i]=i;
    while (!check){
        vector<ll> tmp(A+1, A+k+1);
        res.push_back(tmp);
        sinh();
    }
    for (ll i=res.size()-1; i>=0; i--){
        if (res[i]==v)
            cout<< res.size()-i;
    }
    return 0;
}
