#include <bits/stdc++.h>
using namespace std;

int n, ans=-1e9;
vector<int> A;

int main(){
    freopen("DAYSO.INP", "r", stdin);
    freopen("DAYSO.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>> n;
    A.resize(n+1);
    int Min=1e9;
    for (int i=1; i<=n; i++){
        cin>> A[i];
        Min=min(Min, A[i]);
        ans=max(ans, A[i]-Min);
    }
    cout<< ans;
    return 0;
}
