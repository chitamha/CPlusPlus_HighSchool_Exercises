#include <iostream>
using namespace std;
int main(){
    int n, k, x;
    cin>> n;
    int A[n+1];
    for (int i=0; i<n; i++){
        cin>> A[i];
    }
    cin>> x>> k;
    --k;
    for (int i=n; i>k; i--){
        A[i]=A[i-1];
    }
    A[k]=x;
    for (int i=0; i<n+1; i++){
        cout<< A[i]<< " ";
    }
}
