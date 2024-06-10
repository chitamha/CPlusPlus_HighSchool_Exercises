#include <bits/stdc++.h>
#define maxn 1000006
using namespace std;
using ll=long long;

ll n;
ll NP[100];
vector<string> v;

void Try(ll i){
    for (ll j=0; j<=1; j++){
        NP[i]=j;
        if (i<=n/2){
            string s;
            for (ll k=1; k<=i; k++) s+=to_string(NP[k]);
            for (ll k=i; k>=1; k--) s+=to_string(NP[k]);
            v.push_back(s);
        }
        if (i<n/2) Try(i+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>> n;
    Try(1);
    sort(v.begin(), v.end());
    for (string s:v){
        cout<< s<< endl;
    }
    return 0;
}
