#include <bits/stdc++.h>
#define ll long long
#define maxn 1000006
using namespace std;

int n, X[25]; ll sum=0, ans=1e18;
vector<int> v;

void xuli(){
    ll tmp=0;
    //for (int i=1; i<=n; i++) cout<< X[i]<< " ";
    //cout<< endl;
    for (int i=1; i<=n; i++){
        if (X[i]) tmp+=v[i];
    }
    ans=min(ans, abs(sum-2*tmp));
}

void Try(int i){
    for (int j=0; j<=1; j++){
        X[i]=j;
        if (i==n) xuli();
        else Try(i+1);
    }
}

int main(){
    freopen("CHIAKEO.INP", "r", stdin);
    freopen("CHIAKEO.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n; v.resize(n+1);
    for (int i=1; i<=n; i++) cin>> v[i], sum+=v[i]; {}
    Try(1);
    cout<< ans;
    return 0;
}
