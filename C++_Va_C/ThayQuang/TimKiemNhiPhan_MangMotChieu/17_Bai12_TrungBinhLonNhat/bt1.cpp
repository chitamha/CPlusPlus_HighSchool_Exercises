#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 100006
using namespace std;

int n, k;
vector<int> v;
vector<double> tmp;
vector<pair<int, int>> Min;

bool check(double dec){
    for (int i=1; i<=n; i++) tmp[i]=1.0*v[i]-dec;
    double sum=0.0;
    for (int i=1; i<=n; i++){
        sum+=tmp[i];
        Min[i]=Min[i-1];
        if (sum-Min[i].fi>=0 && i-Min[i].se>=k) return 1;
        if (Min[i].fi>=sum) Min[i]={sum, i};
    }
    return 0;
}

int main(){
    //freopen("AVERAGE.INP", "r", stdin);
    //freopen("AVERAGE.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> k;
    v.resize(n+1, 0);
    tmp.resize(n+1, 0.0);
    Min.resize(n+1, {1000000000.0, 0});
    double l=1000000000.0, r=-l, ans;
    for (int i=1; i<=n; i++){
        cin>> v[i];
        r=max(r, v[i]*1.0);
        l=min(l, v[i]*1.0);
    }
    for (int i=1; i<=200; i++){
        double mid=(l+r)/2.0;
        //cout<< mid<< " "<< l<< " "<< r<< " "<< check(mid)<< endl;
        if (check(mid)){
            ans=mid;
            l=mid;
        } else r=mid;
    }
    cout<< fixed<< setprecision(3)<< ans;
    return 0;
}
