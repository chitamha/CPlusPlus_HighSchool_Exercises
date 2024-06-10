#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n;
bool checkfinal=false;
ll A[100];

void khoitao(){
    for (int i=1; i<=n; i++){
        A[i]=0;
    }
}

void sinh(){
    ll i=n;
    while (i>=1 && A[i]==1){
        A[i]=0;
        i--;
    }
    if (i==0){
        checkfinal=true;
    } else{
        A[i]=1;
    }
}

int main(){
    cin>> n;
    khoitao();
    while (!checkfinal){
        for (ll i=1; i<=n; i++){
            if (A[i]) cout<< char(i+96);
        }
        cout<< endl;
        sinh();
    }
    return 0;
}
