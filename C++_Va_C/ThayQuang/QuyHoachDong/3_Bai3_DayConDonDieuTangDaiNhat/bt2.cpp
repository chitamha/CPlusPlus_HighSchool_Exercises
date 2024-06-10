#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> A, truyvet;

int main(){
    //freopen("DAYCON.INP", "r", stdin);
    //freopen("DAYCON.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>> n;
    A.resize(n);
    for (int i=0; i<n; i++) cin>> A[i];
    for (int i=0; i<n; i++){
        auto it=lower_bound(truyvet.begin(), truyvet.end(), A[i]);
        if (it==truyvet.end())
            truyvet.push_back(A[i]);
        else *it=A[i];
    }
    cout<< truyvet.size()<< endl;
    for (int i:truyvet) cout<< i<< " ";
    return 0;
}
