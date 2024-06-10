#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 1000006
using namespace std;

ll n, m;

int main(){
    //freopen("text1.inp", "r", stdin);
    //freopen("text1.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m;
    vector<pair<ll, ll>> v;
    for (ll i=1; i<=n; i++){
        ll st, en; cin>> st>> en;
        if (en<st) v.push_back({st, en});
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
    //cout<< "In"<< "\n"<< "(Bat dau; Ket thuc)"<< "\n";
    //Bat dau > Ket thuc
    //for (ll i=0; i<n; i++) cout<< i<< ": "<< v[i].fi<< " "<< v[i].se<< "\n";
    ll ans=0, l=v[0].se, r=v[0].fi;
    for (ll i=1; i<n; i++){
        if (r>=v[i].se){ //Giao nhau hay la con; mo rong left, right
            r=max(r, v[i].fi);
            l=min(l, v[i].se);
        } else{ //Khong giao nhau hay la con
            ans+=2*(r-l);
            l=v[i].se; r=v[i].fi;
        }
        cout<< l<< " "<< r<< " "<< ans<< "\n";
    }
    ans+=(r-l)*2;
    cout<< ans+m;
    return 0;
}