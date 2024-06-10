#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, ans=1e9, cmin=1e9;
ll A[1005][1005];
ll X[1005];
bool visited[1005];

ll cnt=0;

void Ql(ll i, ll sum){
    cnt++;
    //if (sum>ans || i>n) return;
    //996 932 lan goi Ql
    for (ll j=1; j<=n; j++){
        if (visited[j]==false){
            X[i]=j;
            visited[j]=true;
            sum+=A[X[i-1]][X[i]];
            if (i==n) ans=min(ans, sum+A[X[n]][1]);
            else if (sum+(n-i+1)*cmin<ans) //180 799 lan goi Ql
                Ql(i+1, sum);
            visited[j]=false;
            sum-=A[X[i-1]][X[i]];
        }
    }
}

int main(){
    cin>> n;
    for (ll i=1; i<=n; i++){
        for (ll j=1; j<=n; j++){
            cin>> A[i][j];
            if (A[i][j]!=0)
                cmin=min(cmin, A[i][j]);
        }
    }
    X[1]=1;
    visited[1]=true;
    Ql(2, 0);
    cout<< ans<< endl;
    cout<< cnt<< endl;
    return 0;
}
