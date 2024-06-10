#include <iostream>
using namespace std;
int n, x;
int A[10000]; long long dathuc;
int main(){
    cin>> n>> x;
    for (int i=0; i<n; i++){
        cin>> A[i];
        if (i==0) {dathuc=(A[0]); dathuc%=1000000007;}
        else if (i<n) {dathuc=(dathuc*x+A[i]); dathuc%=1000000007;}
    }
    cout<< dathuc;
}
