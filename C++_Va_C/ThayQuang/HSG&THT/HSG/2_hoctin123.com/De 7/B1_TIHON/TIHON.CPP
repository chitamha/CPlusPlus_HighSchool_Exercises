#include <bits/stdc++.h>
#define maxn 10006
using namespace std;

int n, ma=0, A[maxn];
int main(){
    freopen("TIHON.INP", "r", stdin);
    freopen("TIHON.OUT", "w", stdout);
    cin>> n;
    for (int i=1; i<=n; i++){
        cin>> A[i];
        ma=max(ma, A[i]);
    }
    vector<int> D(ma+1, 0);
    for (int i=1; i<=ma/2; i++){
        for (int j=2*i; j<=ma; j+=i){
            D[j]+=i;
        }
    }
    int cnt=0;
    for (int i=1; i<=n; i++){
        //cout<< D[A[i]]<< " "<< A[i]<< endl;
        if (D[A[i]]>A[i]) cnt++;
    }
    cout<< cnt;
    return 0;
}
