#include <bits/stdc++.h>
#define ull unsigned long long
#define ld long double
using namespace std;

ull n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    ull l=1, r=1e19, ans;
    while (l<=r){
        ull mid=(l+r)>>1;
        if (mid-(ull)((ld)sqrt((ld)mid))>=n){
            ans=mid;
            r=mid-1;
        } else l=mid+1;
    }
    cout<< ans;
    return 0;
}
