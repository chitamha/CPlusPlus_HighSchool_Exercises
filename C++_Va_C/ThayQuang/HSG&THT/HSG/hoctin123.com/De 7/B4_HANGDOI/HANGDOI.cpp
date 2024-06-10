#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int n, A[maxn], Min[maxn];
int main(){
    //freopen("HANGDOI.inp","r",stdin);
    //freopen("HANGDOI.out","w",stdout);
    cin>> n;
    for (int i=1; i<=n; i++) cin>> A[i];
    Min[n]=A[n];
    for (int i=n-1; i>=1; i--) Min[i]=min(Min[i+1], A[i]);
    for (int i=1; i<=n; i++){
        int j=lower_bound(Min+i+1, Min+n+1, A[i])-Min;
        j--;
        cout<< j-i<< " ";
    }
    return 0;
}
