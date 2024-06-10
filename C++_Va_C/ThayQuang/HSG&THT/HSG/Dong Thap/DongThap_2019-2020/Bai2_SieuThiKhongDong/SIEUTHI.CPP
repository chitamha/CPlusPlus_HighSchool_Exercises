#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

ll n, m, F1[100006], F2[100006], sumv=0;
vector<pair<ll, ll>> v;

void QHD1(){
    for (ll i=1; i<=n; i++){
        for (ll j=v[i].se; j<=m; j++){
            F1[j]=max(F1[j], F1[j-v[i].se]+v[i].fi);
        }
    }
    cout<< F1[m];
}

void QHD2(){
    //F2[i]=j
    //Trọng lượng nhỏ nhất j để đạt giá trị i
    ll ans=0;
    for (ll i=0; i<=sumv; i++) F2[i]=1e18;
    F2[0]=0;
    for (ll i=1; i<=n; i++){
        //Được sử dụng nhiều lần nên for xuôi
        for (ll j=v[i].fi; j<=sumv; j++){
            if (F2[j]>F2[j-v[i].fi]+v[i].se){
                F2[j]=F2[j-v[i].fi]+v[i].se;
            }
            if (F2[j]<=m) ans=max(ans, j);
        }
    }

    cout<< ans;
}

int main(){
    //freopen("SIEUTHI.INP", "r", stdin);
    //freopen("SIEUTHI.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m; v.resize(n+1);
    for (ll i=1; i<=n; i++){
        cin>> v[i].se>> v[i].fi;
        sumv+=v[i].fi;
    }
    //QHD1();
    QHD2();
    return 0;
}
