#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define maxn 100005
using namespace std;

int n, cnt=0;
ll R[maxn], L[maxn], rpS[maxn], A[maxn];

int main(){
    cin>> n;
    for (int i=1; i<=n; i++) cin>> A[i];
    //Reprefix Sum
    rpS[n]=A[n];
    for (int i=n-1; i>=1; i--) rpS[i]=rpS[i+1]+A[i];
    //Right
    R[n]=A[n];
    for (int i=n-1; i>=1; i--) R[i]=min(A[i], R[i+1]+A[i]);
    //Left
    ll sum=A[1];
    L[1]=A[1];
    for (int i=2; i<=n; i++){
        L[i]=min(L[i-1], sum+A[i]);
        sum+=A[i];
    }
    for (int i=1; i<=n; i++){
        if (R[i]>0 && rpS[i]+L[i-1]>0) cnt++;
    }
    cout<< cnt;
    return 0;
}
