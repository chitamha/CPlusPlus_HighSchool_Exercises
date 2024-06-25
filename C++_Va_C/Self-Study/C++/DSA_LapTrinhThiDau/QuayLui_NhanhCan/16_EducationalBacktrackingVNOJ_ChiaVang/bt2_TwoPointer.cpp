#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int n, A[30], ans=0;
vector<pair<int, int>> Chua1, Chua2;

void Try(int l, int r, vector<pair<int, int>> &Vec, int w1, int w2){
    if (l>r){
        Vec.push_back({w1-w2, w1+w2});
        return;
    }
    Try(l+1, r, Vec, w1, w2);
    Try(l+1, r, Vec, w1+A[l], w2);
    Try(l+1, r, Vec, w1, w2+A[l]);
}

bool cmp1(pair<int, int> a, pair<int, int> b){
    if (a.fi!=b.fi) return a.fi<b.fi;
    return a.se>b.se;
}

bool cmp2(pair<int, int> a, pair<int, int> b){
    if (a.fi!=b.fi) return a.fi<b.fi;
    return a.se<b.se;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    for (int i=1; i<=n; i++) cin>> A[i];
    Try(1, n/2, Chua1, 0, 0);
    Try(n/2+1, n, Chua2, 0, 0);
    sort(Chua1.begin(), Chua1.end(), cmp1);
    sort(Chua2.begin(), Chua2.end(), cmp2);
    int l=0, r=Chua2.size()-1;
    while (l<Chua1.size() && r>=0){
        if (Chua1[l].fi+Chua2[r].fi==0) ans=max(ans, Chua1[l].se+Chua2[r].se);
        if (Chua1[l].fi+Chua2[r].fi>=0) r--;
        else l++;
    }
    cout<< ans/2;
    return 0;
}
