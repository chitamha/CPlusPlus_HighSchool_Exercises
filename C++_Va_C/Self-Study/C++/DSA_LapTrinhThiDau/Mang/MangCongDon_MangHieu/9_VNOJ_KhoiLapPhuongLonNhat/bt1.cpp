#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 1000005
using namespace std;

int n, ans=0, V[35][35][35], pS[35][35][35];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>> t;
    while (t--){
        cin>> n;
        //0 + 1 - 2 + 3
        for (int i=1; i<=n; i++){
            for (int j=1; j<=n; j++){
                for (int k=1; k<=n; k++){
                    int x; cin>> x;
                    pS[i][j][k]=pS[i-1][j][k]+pS[i][j-1][k]+pS[i][j][k-1]-pS[i-1][j-1][k]-pS[i][j-1][k-1]-pS[i-1][j][k-1]+pS[i-1][j-1][k-1]+x;
                }
            }
        }
        //- + -
        for (int c=1; c<=n; c++){
            for (int i=c; i<=n; i++){
                for (int j=c; j<=n; j++){
                    for (int k=c; k<=n; k++){
                        ans=max(ans, pS[i][j][k]-pS[i-c][j][k]-pS[i][j-c][k]-pS[i][j][k-c]+pS[i-c][j-c][k]+pS[i][j-c][k-c]+pS[i-c][j][k-c]-pS[i-c][j-c][k-c]);
                    }
                }
            }
        }
        cout<< ans<< endl;
        memset(V, 0, sizeof V);
        memset(pS, 0, sizeof pS);
        ans=0;
    }
    return 0;
}
