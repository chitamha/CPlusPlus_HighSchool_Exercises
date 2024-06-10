#include <bits/stdc++.h>
using namespace std;

int t;
vector<int> v;

int main(){
    cin>> t;
    while (t--){
        int n, k;
        long long ans=0;
        cin>> n>> k;
        for (int i=0; i<n; i++){
            int x; cin>> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        for (int i=0; i<n; i++){
            auto it1=upper_bound(v.begin()+i+1, v.end(), k-v[i]);
            auto it2=lower_bound(v.begin()+i+1, v.end(), k-v[i]);
            ans+=it1-it2;
        }
        cout<< ans<< endl;
        v.clear();
    }
    return 0;
}
