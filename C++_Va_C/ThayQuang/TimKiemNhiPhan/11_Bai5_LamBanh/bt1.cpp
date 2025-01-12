#include <bits/stdc++.h>
#define ll long long
using namespace std;

string s;
ll N[4], P[4], Dem[4], R, ans=-1;

bool check(ll sl){
    return max(0ll, (Dem[1]*sl-N[1]))*P[1]+max(0ll, (Dem[2]*sl-N[2]))*P[2]+max(0ll, (Dem[3]*sl-N[3]))*P[3]<=R;
}

int main(){
    //freopen("HUMBERGER.INP", "r", stdin);
    //freopen("HUMBERGER.OUT", "w", stdout);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> s;
    for (ll i=1; i<=3; i++) cin>> N[i];
    for (ll i=1; i<=3; i++) cin>> P[i];
    cin>> R;
    for (char c:s){
        if (c=='B') Dem[1]++;
        else if (c=='S') Dem[2]++;
        else if (c=='C') Dem[3]++;
    }
    ll left=0, right=1e15;
    while (left<=right){
        ll mid=(left+right)/2;
        if (check(mid)){
            ans=mid;
            left=mid+1;
        } else right=mid-1;
    }
    cout<< ans;
    return 0;
}
