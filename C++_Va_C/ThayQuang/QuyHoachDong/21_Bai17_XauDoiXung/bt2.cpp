#include <bits/stdc++.h>
#define maxn 5005
using namespace std;

int n, F[maxn][maxn];
string s;

int main(){
    //freopen("PALIN.INP", "r", stdin);
    //freopen("PALIN.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n; cin.ignore();
    cin>> s;
    s=' '+s;
    memset(F, 62, sizeof F);
    for (int i=0; i<=n; i++) F[i][i]=0;
    for (int i=n; i>=1; i--){
        for (int j=i+1; j<=n; j++){
            if (s[i]==s[j]){
                F[i][j]=F[i+1][j-1];
            } else F[i][j]=min(F[i][j-1], F[i+1][j])+1;
        }
    }
    /*
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++) cout<< F[i][j]<< " ";
        cout<< endl;
    }
    */
    cout<< F[1][n];
    return 0;
}
