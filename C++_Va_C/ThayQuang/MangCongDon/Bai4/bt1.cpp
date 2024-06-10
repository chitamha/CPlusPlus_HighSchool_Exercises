#include <bits/stdc++.h>
#define maxn 1000001
using namespace std;

int n, t, l, r, v, A[maxn], preS[maxn];
vector<int> B(maxn);
int main(){
    cin>> n;
    for (int i=1; i<=n; i++){
        cin>> A[i];
    }
    cin>> t;
    while (t--){
        cin>> l >> r>> v;
        B[l+1]+=v;
        B[r+2]-=v;
    }
    preS[0]=0;
    for (int i=1; i<=n; i++){
        preS[i]=preS[i-1]+B[i];
        A[i]+=preS[i];
        cout<< A[i]<< " ";
    }
}
