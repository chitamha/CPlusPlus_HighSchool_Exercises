#include <bits/stdc++.h>
using namespace std;

int n, m, T[200005], A[200005], cnt=0;

int main(){
    cin>> n>> m;
    T[1]=0;
    for (int i=1; i<=n; i++){
        int k; cin>> T[i+1]>> k;
        T[i+1]+=T[i];
        for (int j=cnt+1; j<=cnt+k; j++){
            cin>> A[j];
            A[j]=max(A[j]-T[i], 0);
        }
        cnt+=k;
    }
    sort(A+1, A+cnt+1);
    cout<< T[n+1]+A[m];
    return 0;
}
