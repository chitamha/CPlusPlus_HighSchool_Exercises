#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 100006
using namespace std;

int n, d;
double ma=0.0, mi=1000000000.0, ans;
vector<int> A;
vector<double> tmp, Min;

bool check(double x){
    for (int i=1; i<=n; i++) tmp[i]=A[i]*1.0-x;
    double sum=0.0;
    Min[0]=0.0;
    for (int i=1; i<=d-1; i++){
        sum+=tmp[i];
        Min[i]=min(Min[i-1], sum);
    }
    for (int i=d; i<=n; i++){
        sum+=tmp[i];
        if (sum-Min[i-d]>=0) return true;
        Min[i]=min(Min[i-1], sum);
    }
    return false;
}

int main(){
    freopen("TSDOAN.INP", "r", stdin);
    freopen("TSDOAN.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> d;
    A.resize(n+5, 0);
    tmp.resize(n+5, 0.0);
    Min.resize(n+5, 0.0);
    for (int i=1; i<=n; i++){
        cin>> A[i];
        mi=min(mi, A[i]*1.0);
        ma=max(ma, A[i]*1.0);
    }
    double l=mi, r=ma;
    for (int i=1; i<=200; i++){
        double mid=(l+r)/2;
        if (check(mid)){
            ans=mid;
            l=mid;
        } else r=mid;
    }
    cout<< fixed<< setprecision(5)<< ans;
    return 0;
}
