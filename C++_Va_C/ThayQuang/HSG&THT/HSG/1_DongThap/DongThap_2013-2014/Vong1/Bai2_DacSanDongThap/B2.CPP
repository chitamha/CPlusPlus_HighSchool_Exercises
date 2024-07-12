#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll a, b, c, n, m, k;
vector<int> v;

int main(){
    freopen("DACSAN.INP", "r", stdin);
    freopen("DACSAN.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>> t;
    while (t--){
    cin>> a>> b>> c;
    n=a%3; m=b%3; k=c%3;
    v.push_back(n); v.push_back(m); v.push_back(k);
    sort(v.begin(), v.end());
    n=v[0]; m=v[1]; k=v[2];
    ll ans=a/3+b/3+c/3;
    if (n==0 && m==2 && k==2) cout<< ans+1;
    else if (n==1 && m==1 && k==1) cout<< ans+1;
    else if (n==1 && m==1 && k==2) cout<< ans+1;
    else if (n==1 && m==2 && k==2) cout<< ans+1;
    else if (n==2 && m==2 && k==2) cout<< ans+2;
    else cout<< ans;
    cout<< endl;
    v.clear();
    }
    return 0;
}
