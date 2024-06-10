#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int t, n;
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b){
    if (a.fi!=b.fi) return a.fi<b.fi;
    else return a.se>=b.se;
}

int main(){
    cin>> t;
    while (t--){
        cin>> n; v.resize(n);
        for (int i=0; i<n; i++) cin>> v[i].fi>> v[i].se;
        sort(v.begin(), v.end(), cmp);
        vector<int> inc;
        for (int i=n-1; i>=0; i--){
            auto it=lower_bound(inc.begin(), inc.end(), v[i].se);
            if (it==inc.end()) inc.push_back(v[i].se);
            else *it=v[i].se;
        }
        cout<< inc.size()<< "\n";
        v.clear();
    }
    return 0;
}
