#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, x, y, ans;

bool check (int time, int n, int x, int y){
    return time/x+time/y>=n;
}

int main(){
    cin>> n>> x>> y;
    ll l=0, r=n*min(x, y);
    n--;
    while (l<=r){
        ll mid=(l+r)/2;
        if (check(mid, n, x, y)){
            ans=mid;
            r=mid-1;
        } else l=mid+1;
    }
    cout<< ans+min(x, y);
    return 0;
}
