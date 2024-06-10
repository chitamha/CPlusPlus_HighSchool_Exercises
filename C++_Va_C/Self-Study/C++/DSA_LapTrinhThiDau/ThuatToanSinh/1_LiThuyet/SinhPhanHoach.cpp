#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll n, cnt;
bool check=false;
ll A[100];

void sinh(){
    ll i=cnt;
    while (i>=1 && A[i]==1){
        i--;
    }
    if (i==0) check=true;
    else{
        A[i]--;
        ll d=cnt-i+1;
        ll nguyen=d/A[i];
        ll du=d%A[i];
        cnt=i;
        for (ll j=1; j<=nguyen; j++){
            cnt++;
            A[cnt]=A[i];
        }
        if (du!=0){
            cnt++;
            A[cnt]=du;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>> n;
    A[1]=n;
    cnt=1;
    while (!check){
        for (ll i=1; i<=cnt; i++) cout<< A[i]<< " ";
        cout<< endl;
        sinh();
    }
    return 0;
}
