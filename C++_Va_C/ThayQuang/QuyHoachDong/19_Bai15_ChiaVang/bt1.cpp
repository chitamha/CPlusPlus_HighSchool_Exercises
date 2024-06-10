#include <bits/stdc++.h>
#define maxn 105
using namespace std;

int n, A[maxn], F[maxn*205], sum=0;

int main(){
    //freopen("DIVGOLD.INP", "r", stdin);
    //freopen("DIVGOLD.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    for (int i=1; i<=n; i++){
        cin>> A[i];
        sum+=A[i];
    }
    F[0]=1;
    int ma=0;
    for (int i=1; i<=n; i++){
        for (int s=sum/2; s>=A[i]; s--){
            F[s]+=F[s-A[i]];
            if (F[s]) ma=max(ma, s);
        }
    }
    cout<< sum-2*ma<< endl;
    cout<< F[ma];
    return 0;
}
