#include <bits/stdc++.h>
using namespace std;

int n, ans=0, X[30], Cnt[300];
vector<string> vS;

void xuli(){
    memset(Cnt, 0, sizeof Cnt);
    for (int i=1; i<=n; i++)
        if (X[i]==1) for (char c:vS[i]) Cnt[c]=1;
    int dem=0;
    for (char c='a'; c<='z'; c++) dem+=Cnt[c];
    ans+=dem==26;
}

void Try(int i){
    for (int j=0; j<=1; j++){
        X[i]=j;
        if (i==n) xuli();
        else Try(i+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n; vS.resize(n+1);
    for (int i=1; i<=n; i++) cin>> vS[i];
    Try(1);
    cout<< ans;
    return 0;
}
