#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 100006
#define eps 1e-9
using namespace std;

int n, q, A[maxn], chosen[maxn], selected[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> q;
    for (int i=1; i<=q; i++){
        cin>> A[i];
        chosen[A[i]]=1;
    }
    for (int i=q; i>=1; i--){
        if (selected[A[i]]==0){
            cout<< A[i]<< endl;
            selected[A[i]]=1;
        }
    }
    for (int i=1; i<=n; i++){
        if (chosen[i]==0) cout<< i<< endl;
    }
    return 0;
}
