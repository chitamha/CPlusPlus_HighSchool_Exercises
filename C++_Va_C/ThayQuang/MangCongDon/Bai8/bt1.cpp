#include <bits/stdc++.h>
#define maxn 1000006
using namespace std;

int n, A[maxn], preS[maxn];

int main()
{
    freopen("TONGMAX.INP", "r", stdin);
    freopen("TONGMAX.OUT", "w", stdout);
    cin>> n;
    preS[0]=0;
    for (int i=1; i<=n; i++){
        cin>> A[i];
        preS[i]=preS[i-1]+A[i];
    }
    int maxx=-1e9;
    for (int i=1; i<n; i++){
        for (int j=i+1; j<n+1; j++){
            maxx=max(maxx, preS[j]-preS[i-1]);
        }
    }
    cout<< maxx;
}
