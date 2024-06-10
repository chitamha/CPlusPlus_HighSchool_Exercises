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
    n=m/2;
    for (ll i=1; i<=n; i++) NP[i]=0;
    while (!check){
        string s;
        for (ll i=1; i<=n; i++){
            s+=to_string(NP[i]);
        }
        if (m%2==1) s+='0';
        for (ll i=n; i>=1; i--){
            s+=to_string(NP[i]);
        }
        v.push_back(s);
        if (m%2==1){
            s[(m+1)/2-1]='1';
            v.push_back(s);
        }
        sinh();
    }
    sort(v.begin(), v.end());
    for (string s:v){
        cout<< s<< endl;
    }
    return 0;
}
