#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll t, n, k;
vector<ll> v;

void xuli(){
    for (ll i=1; i<=k; i++){
        v[i]=v[i]+v[i+1];
    }
}

void in(){
    cout<< "[";
    for (ll i=1; i<=k; i++){
        cout<< v[i];
        if (i!=k) cout<< " ";
    }
    cout<< "]"<< endl;
}

int main(){
    cin>> t;
    while (t--){
        cin>> n;
        v.resize(n+1);
        for (ll i=1; i<=n; i++)
            cin>> v[i];
        k=n;
        in();
        k--;
        while (k!=1){
            xuli();
            in();
            k--;
        }
        cout<< "["<< v[1]+v[2]<< "]"<< endl;
        v.clear();
    }
    return 0;
}
