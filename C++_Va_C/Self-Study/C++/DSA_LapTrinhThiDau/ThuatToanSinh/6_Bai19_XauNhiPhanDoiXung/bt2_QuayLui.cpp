#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n;
ll NP[1005];
vector<string> v;

void Try(ll i){
    for (ll j=0; j<=1; j++){
        NP[i]=j;
        if (n%2==0 && i==n/2){
            string s;
            for (ll k=1; k<=i; k++)
                s+=to_string(NP[k]);
            for (ll k=i; k>=1; k--)
                s+=to_string(NP[k]);
            v.push_back(s);
        } else if (n%2==1 && i==(n+1)/2){
            string s;
            for (ll k=1; k<=i; k++)
                s+=to_string(NP[k]);
            for (ll k=i-1; k>=1; k--)
                s+=to_string(NP[k]);
            v.push_back(s);
        } else Try(i+1);
    }
}

int main(){
    cin>> n;
    Try(1);
    sort(v.begin(), v.end());
    for (string s:v)
        cout<< s<< endl;
    return 0;
}
