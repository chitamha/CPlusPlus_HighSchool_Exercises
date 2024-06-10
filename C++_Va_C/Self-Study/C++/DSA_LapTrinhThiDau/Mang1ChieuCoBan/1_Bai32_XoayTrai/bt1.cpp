#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, k; cin>> n>> k;
    k=k%n;
    int A[n];
    for (int i=0; i<n; i++) cin>> A[i];
    int tam1, tam2;
    for (int j=0; j<k; j++){
        tam1=A[n-1];
        for (int i=n-2; i>=0; i--){
                tam2=A[i];
                A[i]=tam1;
                tam1=tam2;
        }
        A[n-1]=tam1;
    }
    for (int i=0; i<n; i++){
        cout<< A[i]<< " ";
    }
    return 0;
}
