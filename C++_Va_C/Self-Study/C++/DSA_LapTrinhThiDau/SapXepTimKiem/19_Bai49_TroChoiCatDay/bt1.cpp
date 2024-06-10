#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll n, k;
double ans;

bool check(ll A[], ll n, ll k, double mid){
    ll length=0;
    for (int i=0; i<n; i++){
        length+=(int)A[i]/mid;
    }
    return length>=k;
}

int main(){
    cin>> n>> k;
    ll A[n];
    for (ll i=0; i<n; i++) cin>> A[i];
    double left=0, right=10e18;
    for (ll i=0; i<100; i++){
        double mid=(left+right)/2;
        if (check(A, n, k, mid)){
            ans=mid;
            left=mid;
        } else right=mid;
    }
    cout<< fixed<< setprecision(6)<< ans;
    return 0;
}
