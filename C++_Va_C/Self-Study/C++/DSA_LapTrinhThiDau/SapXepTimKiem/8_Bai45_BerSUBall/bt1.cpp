#include <bits/stdc++.h>
using namespace std;

int n, m, ans=0;
vector<int> Boys;
vector<int> Girls;

int main(){
    cin>> n;
    for (int i=1; i<=n; i++){
        int x; cin>> x;
        Boys.push_back(x);
    }
    cin>> m;
    for (int i=1; i<=m; i++){
        int x; cin>> x;
        Girls.push_back(x);
    }
    sort(Boys.begin(), Boys.end());
    sort(Girls.begin(), Girls.end());
    int l=0, r=0;
    while (l<n && r<m){
        if (abs(Boys[l]-Girls[r])<=1){
            ans++;
            l++;
            r++;
        } else if (Boys[l]-Girls[r]>1){
            r++;
        } else{
            l++;
        }
    }
    cout<< ans;
    return 0;
}
