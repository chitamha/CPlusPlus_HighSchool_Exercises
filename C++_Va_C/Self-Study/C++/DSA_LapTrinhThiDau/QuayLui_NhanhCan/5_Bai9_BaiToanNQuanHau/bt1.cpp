#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll t, n, cnt=0;
ll X[100];
ll cot[100], cheo1[100], cheo2[100];

void Ql(ll i){
    for (ll j=1; j<=n; j++){
        if (cot[j]==0 && cheo1[i-j+8]==0 && cheo2[i+j-1]==0){
            X[i]=j;
            cot[j]=1; cheo1[i-j+8]=1; cheo2[i+j-1]=1;
            if (i==n) cnt++;
            else Ql(i+1);
            cot[j]=0; cheo1[i-j+8]=0; cheo2[i+j-1]=0;
        }
    }
}

int main(){
    cin>> t;
    while (t--){
        cin>> n;
        Ql(1);
        cout<< cnt<< endl;
        cnt=0;
    }
    return 0;
}
