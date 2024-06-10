#include <bits/stdc++.h>
#define maxn 1002
using namespace std;

long long n, A[maxn], F[maxn];

int main(){
    cin>> n;
    for (int i=0; i<n; i++){
        cin>> A[i];
        F[i]=1;
    }
    for (int i=1; i<n; i++){
        for (int j=0; j<i; j++){
            if (A[j]<A[i]){
                F[i]=max(F[j]+1, F[i]);
            }
        }
    }
    cout<< *max_element(F, F+n);
}
/*
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>> n;
    int A[n+1], F[n+1];
    for (int i=1; i<=n; i++) cin>> A[i];
    F[0]=1;
    for (int i=1; i<=n; i++){
        F[i]=1;
        for (int j=1; j<i; j++){
            if (A[i]>A[j]){
                F[i]=max(F[i], F[j]+1);
            }
            else F[i]=max(F[i], F[j]);
        }
    }
    cout<< F[n];
    return 0;
}
*/
