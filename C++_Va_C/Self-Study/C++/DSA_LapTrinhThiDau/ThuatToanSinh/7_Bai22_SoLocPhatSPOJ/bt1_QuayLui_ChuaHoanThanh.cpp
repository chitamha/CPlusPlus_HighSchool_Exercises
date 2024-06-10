#include <bits/stdc++.h>
#define ll long long
#define maxn 1000006
using namespace std;

ll n;
ll A[maxn];
ll value[]={6, 8};
vector<string> v;

void Try(ll i){
    for (ll j=0; j<2; j++){
        A[i]=value[j];
        string s;
        for (ll k=1; k<=i; k++) s+=to_string(A[k]);
        for (ll k=i; k>=1; k--) s+=to_string(A[k]);
        v.push_back(s);
        if (v.size()<n) Try(i+1);
    }
}

int main(){
    cin>> n;
    Try(1);
    for (string s:v)
        cout<< s<< endl;
    return 0;
}
