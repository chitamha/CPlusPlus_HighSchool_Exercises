#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, m, ma=0, A[25], S[100005], F[100005];

int main(){
    freopen("ATM.INP", "r", stdin);
    freopen("ATM.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m;
    for (int i=1; i<=n; i++) cin>> A[i];
    for (int i=1; i<=m; i++){
        cin>> S[i];
        ma=max(ma, S[i]);
    }
    F[0]=1;
    for (int i=1; i<=n; i++){
        for (int j=ma; j>=A[i]; j--){
            F[j]=F[j] || F[j-A[i]];
        }
    }
    int cnt=0;
    for (int i=1; i<=m; i++){
        if (F[S[i]]) cnt++;
    }
    cout<< cnt;
    return 0;
}
