#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int n, m;
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.se-a.fi<b.se-b.fi;
}

int main(){
    freopen("COINS.INP", "r", stdin);
    freopen("COINS.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>> n>> m;
    v.resize(n);
    for (int i=0; i<n; i++) cin>> v[i].fi;
    for (int i=0; i<n; i++) cin>> v[i].se;
    sort(v.begin(), v.end(), cmp);
    int i=0;
    while (i<n){
        if (v[i].se-v[i].fi<=m){
            m-=v[i].se-v[i].fi;
            m+=v[i].se;
        } else break;
        i++;
    }
    cout<< m;
    return 0;
}
