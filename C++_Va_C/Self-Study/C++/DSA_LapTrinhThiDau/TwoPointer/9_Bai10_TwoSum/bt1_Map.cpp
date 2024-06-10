#include <bits/stdc++.h>
using namespace std;

map<int, int> mp;
int ans=0;

int main(){
    int n, k;
    cin>> n>> k;
    for (int i=1; i<=n; i++){
        int x; cin>> x;
        mp[x]++;
    }
    for (auto x:mp){
        int key=x.first;
        if (mp.find(k-key)!=mp.end()){
            if (2*key==k && mp[key]==1)
                continue;
            else{
                ans=1;
                break;
            }
        }
    }
    if (ans) cout<< "YES";
    else cout<< "NO";
    return 0;
}
