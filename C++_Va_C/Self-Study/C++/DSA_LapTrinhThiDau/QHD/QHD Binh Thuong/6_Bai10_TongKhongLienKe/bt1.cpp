#include <bits/stdc++.h>
#define maxn 1000006
using namespace std;

long long n, A[maxn];
long long F[maxn];

int main(){
    memset(F, 0, sizeof F);
    cin>> n;
    for (int i=0; i<n; i++){
        cin>> A[i];
    }
    F[0]=A[0];
    F[1]=A[1];
    for (int i=2; i<n; i++){
        for (int j=0; j<i-1; j++){
            F[i]=max(F[j]+A[i], F[i]);
        }
    }
    cout<< F[n-1];
    return 0;
}
/*
#include <bits/stdc++.h>
#define maxn 1000006
using namespace std;

int n, A[maxn];
int F[maxn];

int main(){
    cin>> n;
    for (int i=1; i<=n; i++) cin>> A[i];
    F[0]=0;
    F[1]=A[1];
    for (int i=2; i<=n; i++){
        for (int j=0; j<=i-2; j++)
            F[i]=max(F[i], F[j]+A[i]);
    }
    cout<< F[n];
    return 0;
}
*/
