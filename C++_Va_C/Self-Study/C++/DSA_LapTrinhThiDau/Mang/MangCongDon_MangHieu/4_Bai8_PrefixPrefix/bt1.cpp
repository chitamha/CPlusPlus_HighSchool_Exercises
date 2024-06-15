#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m, k;
    cin>> n>> m>> k;
    int A[n+1];
    int l[m+1], r[m+1], value[m+1];
    int mH1[m+1];
    memset(mH1, 0, sizeof mH1);
    for (int i=1; i<=n; i++) cin>> A[i];
    for (int i=1; i<=m; i++){
        cin>> l[i]>> r[i]>> value[i];
    }
    for (int i=1; i<=k; i++){
        int u, v;
        cin>> u>> v;
        mH1[u]+=1;
        mH1[v+1]-=1;
    }
    for (int i=1; i<=m; i++){
        mH1[i]+=mH1[i-1];
    }
    int mH2[n+1];
    memset(mH2, 0, sizeof mH2);
    for (int i=1; i<=m; i++){
        mH2[l[i]]+=mH1[i]*value[i];
        mH2[r[i]+1]-=mH1[i]*value[i];
    }
    for (int i=1; i<=n; i++){
        mH2[i]+=mH2[i-1];
        cout<< A[i]+mH2[i]<< " ";
    }
    return 0;
}
