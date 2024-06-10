#include <bits/stdc++.h>
#define maxn 30006
using namespace std;

int n, S, W[30], V[30], F[maxn];

int main(){
    freopen("DUAN.INP", "r", stdin);
    freopen("DUAN.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> S;
    for (int i=1; i<=n; i++) cin>> W[i];
    for (int i=1; i<=n; i++) cin>> V[i];
    for (int i=1; i<=n; i++){
        for (int j=S; j>=W[i]; j--){
            F[j]=max(F[j], F[j-W[i]]+V[i]);
        }
    }
    cout<< *max_element(F+1, F+S+1);
    return 0;
}
