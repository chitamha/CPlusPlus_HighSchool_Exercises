#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, ans=1e9; ll mi=2*1e9+10, ma=-(2*1e9+10);
vector<ll> v;
vector<int> Min, Max;

int main(){
    freopen("DOANCON.INP", "r", stdin);
    freopen("DOANCON.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n; v.resize(n+1);
    for (int i=1; i<=n; i++){
        cin>> v[i];
        mi=min(mi, v[i]);
        ma=max(ma, v[i]);
    }
    //cout<< mi<< " "<< ma<< endl;
    for (int i=1; i<=n; i++){
        if (v[i]==mi) Min.push_back(i);
        if (v[i]==ma) Max.push_back(i);
    }
    sort(Min.begin(), Min.end());
    sort(Max.begin(), Max.end());
    //>= dau tien
    //<= cuoi cung
    //Thuong thuong se khong co dau "="
    /*
    for (int x:Min) cout<< x<< " ";
    cout<< endl;
    for (int x:Max) cout<< x<< " ";
    cout<< endl;
    for (int i=0; i<Max.size(); i++){
        auto it1=lower_bound(Min.begin(), Min.end(), Max[i]);
        auto it2=upper_bound(Min.begin(), Min.end(), Max[i])-1;
        if (it1!=Min.end()) ans=min(ans, abs(*it1-Max[i]));
        if (it2!=Min.begin()) ans=min(ans, abs(*it2-Max[i]));
    }
    */
    int i=0, j=0;
    while (i<Min.size() && j<Max.size()){
        ans=min(ans, abs(Min[i]-Max[j]));
        if (Min[i]>Max[j]) j++;
        else i++;
    }
    cout<< ans+1;
    return 0;
}
