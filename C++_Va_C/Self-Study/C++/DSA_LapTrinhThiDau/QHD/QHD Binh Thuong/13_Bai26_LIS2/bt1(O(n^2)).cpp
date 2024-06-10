#include <bits/stdc++.h>
#define maxn 1000006
using namespace std;

long long n, A[maxn], F[maxn];

int main(){
    cin>> n;
    for (int i=0; i<n; i++){
        cin>> A[i];
    }
    F[0]=1;
    for (int i=1; i<n; i++){
        for (int j=0; j<i; j++){
            if (A[j]<A[i]){
                F[i]=max(F[j]+1, F[i]);
            }
        }
    }
    cout<< *max_element(F, F+n);
    return 0;
}
