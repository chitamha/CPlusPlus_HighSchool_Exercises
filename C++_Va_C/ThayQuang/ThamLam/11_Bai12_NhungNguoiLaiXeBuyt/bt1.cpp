#include <bits/stdc++.h>
using namespace std;

int n, d, R;
vector<int> ngay;
vector<int> dem;

int main(){
    freopen("BUSDRIVER.INP", "r", stdin);
    freopen("BUSDRIVER.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while (1){
        cin>> n>> d>> R;
        if (n==0 && d==0 && R==0) break;
        ngay.resize(n); dem.resize(n);
        for (int i=0; i<n; i++) cin>> ngay[i];
        for (int i=0; i<n; i++) cin>> dem[i];
        sort(ngay.begin(), ngay.end());
        sort(dem.begin(), dem.end());
        int l=0, r=n-1;
        int dis=0;
        while (l<=n-1 && r>=0){
            dis+=max(0, (ngay[l]+dem[r])-d);
            l++;
            r--;
        }
        cout<< 1ll*dis*R<< endl;
        ngay.clear();
        dem.clear();
    }
    return 0;
}
