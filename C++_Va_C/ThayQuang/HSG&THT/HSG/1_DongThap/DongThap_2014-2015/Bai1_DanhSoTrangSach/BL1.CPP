#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, Dem[15];

void xuli(ll i){
    string s=to_string(i);
    for (int i=0; i<s.size(); i++){
        int x=int(s[i])-48;
        Dem[x]++;
    }
}

int main(){
    freopen("SOTRANG.INP", "r", stdin);
    freopen("SOTRANG.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>> n;
    for (ll i=1; i<=n; i++){
        xuli(i);
    }
    for (ll i=0; i<=9; i++){
        cout<< i<< " "<< Dem[i]<< endl;
    }
    return 0;
}
