#include <iostream>
#include <math.h>
using namespace std;
int tbp(int i, int A[10000]){
    int sum=0;
    for (int j=0; j<i; j++){
        sum+=A[j];
    }
    return sum;
}
int tbt(int i, int n, int A[10000]){
    int sum=0;
    for (int j=i+1; j<n; j++){
        sum+=A[j];
    }
    return sum;
}
bool ktsnt(int n){
    if (n<=1) return false;
    for (int i=2; i<=sqrt(n); i++){
        if (n%i==0){
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    cin>> n;
    int A[n];
    for (int i=0; i<n; i++){
        cin>> A[i];
    }
    for (int i=0; i<n; i++){
        if ((ktsnt(tbp(i, A))) && (ktsnt(tbt(i, n, A)))){
            cout<< i<< endl;
        }
    }
}
