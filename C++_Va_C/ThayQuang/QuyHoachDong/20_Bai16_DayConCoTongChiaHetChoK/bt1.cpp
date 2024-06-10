/*
#include <bits/stdc++.h>
#define maxn 1005
#define ll long long
using namespace std;

ll n, k, sum=0, A[maxn], F[maxn][50];

int main(){
    //freopen("DAYK.INP", "r", stdin);
    //freopen("DAYK.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> k;
    for (ll i=1; i<=n; i++){
        cin>> A[i];
        A[i]=(A[i]+100000000000000*k)%k;
        sum+=A[i];
    }
    memset(F, 62, sizeof F);
    F[0][0]=0;
    for (ll i=1; i<=n; i++){
        for (ll j=0; j<k; j++){
            F[i][j]=min(F[i-1][j], F[i-1][(j-A[i]+k)%k]+1);
        }
    }
    cout<< n-F[n][sum%k];
    return 0;
}
*/
#include <bits/stdc++.h>
#define maxn 1005
#define ll long long
using namespace std;

ll n, k, A[maxn], F[maxn][50];

int main(){
    //freopen("DAYK.INP", "r", stdin);
    //freopen("DAYK.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> k;
    for (ll i=1; i<=n; i++){
        cin>> A[i];
        A[i]=(A[i]+100000000000000*k)%k;
    }
    for (ll i=1; i<k; i++) F[1][i]=-1e9-10;
    F[1][A[1]]=1;
    for (ll i=2; i<=n; i++){
        for (ll j=0; j<k; j++){
            F[i][j]=max({F[i-1][j], F[i-1][(j-A[i]+k)%k]+1});
        }
    }
    cout<< F[n][0];
    return 0;
}
