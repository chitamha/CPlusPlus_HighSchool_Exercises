#include <bits/stdc++.h>
#define maxn 1000006
using namespace std;
using ll=long long;

ll n, m;
ll NP[100];
vector<string> v;
bool check=false;

void sinh(){
    ll i=n;
    while (i>=1 && NP[i]){
        NP[i]=0;
        i--;
    }
    if (i==0) check=true;
    else NP[i]=1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>> m;
    for (ll i=1; i<=n; i++) NP[i]=0;
    for (n=1; n<=m/2; n++){
        check=false;
        while (!check){
            string s;
            for (ll i=1; i<=n; i++){
                s+=to_string(NP[i]);
            }
            for (ll i=n; i>=1; i--){
                s+=to_string(NP[i]);
            }
            v.push_back(s);
            sinh();
        }
    }
    sort(v.begin(), v.end());
    for (string s:v){
        cout<< s<< endl;
    }
    return 0;
}
