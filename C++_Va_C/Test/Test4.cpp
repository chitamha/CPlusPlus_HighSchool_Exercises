#include <bits/stdc++.h>
#define maxn 50000006
using namespace std;

int n;
vector<int> A, v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    freopen("TOWER3.INP", "r", stdin);
    freopen("TOWER2.OUT", "w", stdout);
    cin>> n;
    for (int i=1; i<=n; i++){
        int r, h; cin>> r>> h;
        A.insert(A.end(), h, r);
    }
    for (int i=A.size()-1; i>=0; i--){
        auto it=upper_bound(v.begin(), v.end(), A[i]);
        if (it==v.end()) v.push_back(A[i]);
        else *it=A[i];
    }
    cout<< v.size();
    return 0;
}
