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
    for (int i=1; i<n; i++){
        for (int j=0; j<i; j++){
            if (A[j]<A[i]){
                F[i]=max(F[j]+A[i], F[i]);
            }
            cout<< F[i]<< " ";
        }
        cout<< endl;
    }
    cout<< *max_element(F, F+n);
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;

long long n;
long long A[1005], F[1005];

int main(){
    cin>> n;
    for (int i=1; i<=n; i++){
        cin>> A[i];
        F[i]=A[i];
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<i; j++){
            if (A[i]>A[j]){
                F[i]=max(F[i], F[j]+A[i]);
            }
        }
    }
    cout<< *max_element(F+1, F+n+1);
    return 0;
}
*/
