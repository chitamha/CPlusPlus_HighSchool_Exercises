#include <bits/stdc++.h>
#define maxn 1000006
using namespace std;

int A[maxn], F[maxn], preSF[maxn];
int n, q;

int main()
{
    cin>> n>> q;
    for (int i=0; i<n; i++) cin>> A[i];
    F[0]=A[0];
    for (int i=1; i<n; i++) F[i]=A[i]-A[i-1];
    int k, l, r;
    while (q--){
        cin>> l>> r>> k;
        F[l]+=k;
        F[r+1]-=k;
    }
    preSF[0]=F[0];
    for (int i=1; i<n; i++){
        preSF[i]=preSF[i-1]+F[i];
    }
    for (int i=0; i<n; i++)
        cout<< preSF[i]<< " ";
    return 0;
}
