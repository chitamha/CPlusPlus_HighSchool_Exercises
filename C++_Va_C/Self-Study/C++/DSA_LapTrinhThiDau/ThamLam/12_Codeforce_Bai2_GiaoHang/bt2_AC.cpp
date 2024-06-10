#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 1000006
using namespace std;

int n, m;

int main(){
    //freopen("text1.inp", "r", stdin);
    //freopen("text1.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m;
    vector<pair<int, int>> v;
    for (int i=1; i<=n; i++){
        int st, en; cin>> st>> en;
        if (en<st) v.push_back({en, st});
    }
    if (v.size()==0) return cout<< m, 0;
    sort(v.begin(), v.end());
    /*
        a<b: b->a->b => 2(b-a)
        Giao: (c; a) (d; b)
        a<b<c<d: c->a->c->d->b->d
        c->d: 2(c-a+d-b)+d-c>d-c+2(d-a)
        Nằm trong: (c; b) (d; a)
        a<b<c<d: c->b->c->d->a->d
        c->d: 2(c-b+d-a)+d-c>d-c+2(d-a)
    */
    n=v.size();
    //cout<< "In"<< "\n"<< "(Ket thuc; Bat dau)"<< "\n";
    //for (int i=0; i<n; i++) cout<< i<< ": "<< v[i].fi<< " "<< v[i].se<< "\n";
    ll ans=0; int l=v[0].fi, r=v[0].se;
    for (int i=0; i<n; i++){
        //cout<< l<< " "<< r<< " "<< ans<< "\n";
        if (v[i].fi>r){
            ans+=(r-l)*2;
            l=v[i].fi; r=v[i].se;
        } else r=max(r, v[i].se);
    }
    ans+=(r-l)*2;
    cout<< ans+m;
    return 0;
}