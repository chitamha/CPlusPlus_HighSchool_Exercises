#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int n, x;
int A[1000001], F[1000001];

int main(){
    cin>> n>> x;
    for (int i=0; i<n; i++){
        cin>> A[i];
        F[A[i]]=1;
    }
    F[0]=0;
    for (int i=1; i<=x; i++){
        for (int j=0; j<n; j++){
            if (i>=A[j]){
                (F[i]+=F[i-A[j]])%=MOD;
            }
        }
        cout<< "So cach tao nen "<< i<< " la: "<< F[i]<< endl;
    }
    cout<< F[x];
}
