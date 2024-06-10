#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

int main(){
    freopen("CLB.INP", "r", stdin);
    freopen("CLB.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n; v.resize(n+1);
    for (int i=1; i<=n; i++) cin>> v[i];
    sort(v.begin()+1, v.begin()+n+1);
    for (int i=1; i<=n; i++){
        if (binary_search(v.begin()+1, v.begin()+n+1, i)==false)
            return cout<< i, 0;
    }
    cout<< n+1;
    return 0;
}
