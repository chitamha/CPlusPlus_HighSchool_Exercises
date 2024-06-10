#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> v;
multiset<int> mse;

int main(){
    cin>> n>> k;
    v.resize(n+1);
    for (int i=1; i<=n; i++) cin>> v[i];
    for (int i=1; i<=k; i++) mse.insert(v[i]);
    for (int i=1; i<=n-k+1; i++){
        cout<< *(mse.begin())<< " ";
        if (v[i]==*(mse.begin())){
            auto it=mse.find(v[i]);
            mse.erase(it);
        }
        mse.insert(v[i+k]);
    }
    return 0;
}
