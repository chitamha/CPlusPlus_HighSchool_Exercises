#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int n, k, p;
map<int, int> mp;

int main(){
    freopen("BANK.INP", "r", stdin);
    freopen("BANK.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    while (cin>>n){
        if (n==0) break;
        if (n==1){
            cin>> k>> p;
            mp[p]=k;
        }
        if (mp.size()!=0){
            if (n==2){
                cout<< (*mp.rbegin()).se<< endl;
                mp.erase((*mp.rbegin()).fi);
            }
            if (n==3){
                cout<< (*mp.begin()).se<< endl;
                mp.erase((*mp.begin()).fi);
            }
        } else cout<< 0<< endl;
    }
    return 0;
}
