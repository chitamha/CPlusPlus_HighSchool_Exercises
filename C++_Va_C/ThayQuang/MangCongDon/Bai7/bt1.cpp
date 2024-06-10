#include <bits/stdc++.h>
#define maxn 1000006
using namespace std;

int n, A[maxn], preS[maxn], dem=0;
bool cnt(int i){
    if (preS[i]>=preS[n]-preS[i]){
        return 1;
    } else return 0;
}

int main(){
    freopen("CHIAMANG.INP", "r", stdin);
    freopen("CHIAMANG.OUT", "w", stdout);
    cin>> n;
    preS[0]=0;
    for (int i=1; i<n+1; i++){
        cin>> A[i];
        preS[i]=preS[i-1]+A[i];
    }
    for (int i=1; i<n; i++){
        if (cnt(i)) dem++;
    }
    cout<< dem;
    return 0;
}
