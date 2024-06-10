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
    sort(v.begin(), v.end());
    for (int i=1; i<=n-3 && !ans; i++){
        for (int j=i; j<=n-2 && !ans; j++){
            int l=j+1, r=n;
            while (l<r && !ans){
                if (v[l]+v[r]==k-v[i]-v[j]) ans=1;
                else if (v[l]+v[r]>k-v[i]-v[j]) r--;
                else l++;
            }
        }
    }
    if (ans) cout<< "YES";
    else cout<< "NO";
    return 0;
}
