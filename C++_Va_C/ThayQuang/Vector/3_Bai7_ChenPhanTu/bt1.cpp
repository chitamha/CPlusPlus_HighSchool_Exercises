#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main(){
    int n, x, k; cin>> n>> x>> k;
    v.resize(n);
    for (int i=0; i<n; i++) cin>> v[i];
    v.insert(v.begin()+k, x);
    for (auto x:v) cout<< x<< " ";
    return 0;
}
