#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll t, n, check=0;
ll A[15][15];
string s="";

void Ql(ll i, ll j){
    if (i==n && j==n){
        check=1;
        cout<< s<< endl;
        return;
    }
    if (i+1<=n && A[i+1][j]==1){
        s+='D';
        //co hay khong cung duoc
        //A[i+1][j]=0;
        Ql(i+1, j);
        s.pop_back();
        //A[i+1][j]=1;
    }
    if (j+1<=n && A[i][j+1]==1){
        s+='R';
        //A[i][j+1]=0;
        Ql(i, j+1);
        s.pop_back();
        //A[i][j+1]=1;
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
