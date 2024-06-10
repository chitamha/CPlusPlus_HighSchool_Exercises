#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define ii pair<int, int>
#define maxn 500005
#define llll pair<ll, ll>
using namespace std;

ll n;
vector<llll> v;
ll Min[maxn], Dis[maxn];
ll MinDis[maxn], preS[maxn];
bool cmp(llll a, llll b){
    return a.se<b.se;
}

int main(){
    freopen("CALLFOOD.INP", "r", stdin);
    freopen("CALLFOOD.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    v.resize(n+1);
    for (int i=1; i<=n; i++)
        cin>> v[i].fi>> v[i].se;
    sort(v.begin()+1, v.end(), cmp);
    //Min[i]: min của A[i] -> A[n]
    ll mi=v[n].fi;
    Min[n]=mi;
    for (int i=n-1; i>=1; i--){
        mi=min(mi, v[i].fi);
        Min[i]=mi;
    }
    //Tổng từ B[1] -> B[i] của mảng B
    //Distance giữa A[i] và B[i]
    for (int i=1; i<=n; i++){
        preS[i]=preS[i-1]+v[i].se;
        Dis[i]=v[i].fi-v[i].se;
    }
    //MinDis[i]: min của Dis[1] -> Dis[i]
    ll mi2=Dis[1]; MinDis[1]=Dis[1];
    for (int i=2; i<=n; i++){
        mi2=min(mi2, Dis[i]);
        MinDis[i]=mi2;
    }
    for (int i=1; i<=n; i++)
        cout<< min(preS[i]+MinDis[i], preS[i-1]+Min[i])<< endl;
    return 0;
}
