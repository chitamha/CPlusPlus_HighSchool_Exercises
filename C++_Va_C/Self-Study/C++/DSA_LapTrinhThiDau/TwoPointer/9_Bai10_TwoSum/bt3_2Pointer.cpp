#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int ans=0;

int main(){
    int n, k;
    cin>> n>> k;
    v.resize(n+1);
    for (int i=1; i<=n; i++){
        cin>> v[i];
    }
    int l=1, r=n;
    while (l<r && !ans){
        if (v[l]+v[r]==k) ans=1;
        else if (v[l]+v[r]>k) r--;
        else l++;
    }
    if (ans) cout<< "YES";
    else cout<< "NO";
    return 0;
}
