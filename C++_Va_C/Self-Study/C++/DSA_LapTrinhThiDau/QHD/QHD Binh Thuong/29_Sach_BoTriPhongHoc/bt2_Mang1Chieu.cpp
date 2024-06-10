#include <bits/stdc++.h>
#define maxn 10006
using namespace std;

int n, k;
int ph[maxn], hs[maxn], F[maxn];

int main(){
    cin>> n>> k;
    for (int i=1; i<=n; i++) cin>> ph[i];
    for (int i=1; i<=k; i++) cin>> hs[i];
    if (n==k){
        int sum=0;
        for (int i=1; i<=n; i++) sum+=abs(hs[i]-ph[i]);
        return cout<< sum, 0;
    }
    int cnt=1;
    for (int j=1; j<=n; j++){
        for (int i=cnt; i>=1; i--){
            if (i==j) F[i]=F[i-1]+abs(hs[i]-ph[j]);
            else F[i]=min(F[i], F[i-1]+abs(hs[i]-ph[j]));
            //cout<< "("<< i<< ";"<< j<< ") : "<< F[i]<< endl;
        }
        if (cnt+1<=k) cnt++;
    }
    cout<< F[k];
    return 0;
}
