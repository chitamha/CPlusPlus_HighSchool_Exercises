#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll r, d, n, ans;

bool check(ll canh){
    return (canh/r)*(canh/d)>=n;
}
int main(){
    cin>> r>> d>> n;
    ll left=1, right=max(r, d)*n;
    while (left<=right){
        ll mid=(left+right)/2;
        if (check(mid)){
            ans=mid;
            right=mid-1;
        } else left=mid+1;
    }
    cout<< ans;
    return 0;
}
