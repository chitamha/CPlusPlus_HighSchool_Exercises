#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("PHANTICH.INP", "r", stdin);
    freopen("PHANTICH.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin>> n;
    int F[n+1];
    memset(F, 0, sizeof F);
    F[0]=1;
    for (int i=1; i<=min(n, 9); i++){
        for (int j=1; j<=n; j++){
            if (j-i>=0)
                F[j]+=F[j-i];
        }
    }
    /*
    for (int i=0; i<=n; i++)
        cout<< F[i]<< " ";
    cout<< endl;
    */
    cout<< F[n];
    return 0;
}
