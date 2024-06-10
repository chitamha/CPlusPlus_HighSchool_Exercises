#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll m, n;
ll A[100];

void Ql(ll i){
    for (ll j=0; j<=1; j++){
        A[i]=j;
        if (A[1]==1){
            if (i==n){
                string s;
                for (ll h=1; h<=n; h++){
                    if (A[h]==1) s+=char('{');
                    else s+=char('}');
                }
                for (ll h=n; h>=1; h--){
                    if (A[h]==1) s+=char('}');
                    else s+=char('{');
                }
                cout<< s<< endl;
            } else Ql(i+1);
        }
    }
}

int main(){
    cin>> m;
    if (m%2==0){
        for (n=1; n<=m/2; n++){
            Ql(1);
        }
    } else cout<< "NOT FOUND";
    return 0;
}
