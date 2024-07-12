#include <bits/stdc++.h>
#define ll long long
#define maxn 1000006
using namespace std;

int n, s, q, F[50006], ans=0;

int main(){
    freopen("PO.INP", "r", stdin);
    freopen("PO.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> s>> q;
    F[0]=1;
    for (int i=1; i<=n; i++){
        int x; cin>> x;
        for (int j=s; j>=x; j--){
            F[j]+=F[j-x];
            if (F[j]!=0) ans=max(ans, j);
        }
    }
    cout<< ans<< endl;
    if (q==2) cout<< F[ans];
    return 0;
}
