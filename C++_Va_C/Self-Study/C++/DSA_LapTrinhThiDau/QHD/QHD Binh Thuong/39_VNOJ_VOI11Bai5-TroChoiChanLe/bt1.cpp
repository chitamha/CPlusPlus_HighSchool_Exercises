#include <bits/stdc++.h>
#define ll long long
#define maxn 505
using namespace std;

ll n, preS[maxn][maxn], F[maxn][maxn];

ll gethang(int i, int j){
    return preS[i][j]-preS[i-1][j];
}

ll getcot(int i, int j){
    return preS[i][j]-preS[i][j-1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>> t;
    while (t--){
        cin>> n;
        memset(preS, 0, sizeof preS);
        memset(F, 0, sizeof F);
        for (int i=1; i<=n; i++){
            for (int j=1; j<=n; j++){
                int x; cin>> x;
                preS[i][j]=preS[i-1][j]+preS[i][j-1]-preS[i-1][j-1]+x;
                F[i][j]=F[i][j] || (F[i][j-1]==0 && !(getcot(i, j)&1)) || (F[i-1][j]==0 && !(gethang(i, j)&1));
            }
        }
        if (F[n][n]) cout<< "YES"<< "\n";
        else cout<< "NO"<< "\n";
    }
    return 0;
}
