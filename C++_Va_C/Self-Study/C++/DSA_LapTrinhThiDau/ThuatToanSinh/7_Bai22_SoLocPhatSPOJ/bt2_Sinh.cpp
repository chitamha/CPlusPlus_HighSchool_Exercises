#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, k;
bool checkfinal=false;
ll A[1000];
vector<string> v;

void init(){
    for (ll i=1; i<=n; i++)
        A[i]=6;
}

void sinh(){
    ll i=n;
    while (i>=1 && A[i]==8){
        A[i]=6;
        i--;
    }
    if (i==0) checkfinal=true;
    else A[i]=8;
}

int main(){
    cin>> k;
    for (n=1; v.size()<k; n++){
        checkfinal=false;
        init();
        while (!checkfinal && v.size()<k){
            string s="";
            for (ll i=1; i<=n; i++) s+=to_string(A[i]);
            for (ll i=n; i>=1; i--) s+=to_string(A[i]);
            v.push_back(s);
            sinh();
        }
    }
    ll cnt=1;
    for (string s:v)
        cout<< cnt++<< ": "<< s<< endl;
    return 0;
}
