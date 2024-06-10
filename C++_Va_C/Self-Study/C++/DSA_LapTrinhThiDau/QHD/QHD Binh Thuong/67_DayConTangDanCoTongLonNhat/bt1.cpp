#include <bits/stdc++.h>
#define maxn 10005
using namespace std;

int n;
int A[maxn], F[maxn];

int main(){
    cin>> n;
    for (int i=1; i<=n; i++) cin>> A[i];
    F[1]=A[1];
    for (int i=1; i<=n; i++){
        for (int j=1; j<=i; j++){
            if (A[i]>A[j]){
                F[i]=max(F[i], F[j]+A[i]);
            }
        }
    }
    cout<< *max_element(F+1, F+n+1);
    return 0;
}
