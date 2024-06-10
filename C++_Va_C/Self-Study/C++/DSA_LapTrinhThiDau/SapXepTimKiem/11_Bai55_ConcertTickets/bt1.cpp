#include <bits/stdc++.h>
using namespace std;

int n, m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>> n>> m;
    multiset<long long> h;
    long long t[m];
    for (int i=0; i<n; i++){
        int x; cin>> x;
        h.insert(x);
    }
    for (int i=0; i<m; i++){
        cin>> t[i];
        auto it=h.upper_bound(t[i]);
        if (it!=h.begin()){
            it--;
            cout<< *it<< endl;
            h.erase(it);
        } else{
            cout<< -1<< endl;
        }
    }
    return 0;
}
