#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll t, n, check=0;
ll A[15][15];
ll dx[]={1, 0};
ll dy[]={0, 1};
string s="";

void Ql(ll i, ll j){
    if (i==n && j==n){
        check=1;
        cout<< s<< endl;
    }
    for (ll k=0; k<2; k++){
        ll u=i+dx[k];
        ll v=j+dy[k];
        if (u<=n && v<=n && A[u][v]){
            if (k==0) s+='D';
            else s+='R';
            Ql(u, v);
            s.pop_back();
        }
    }
}

int main(){
    cin>> t;
    while (t--){
        cin>> n;
        for (ll i=1; i<=n; i++)
            for (ll j=1; j<=n; j++)
                cin>> A[i][j];
        Ql(1, 1);
        if (!check) cout<< -1<< endl;
        s="";
        check=0;
    }
    return 0;
}
