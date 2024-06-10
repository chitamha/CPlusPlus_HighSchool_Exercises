#include <iostream>
#include <math.h>
using namespace std;

int n, x, A[10000], sum=0;
int main(){
    cin>> n>> x;
    for (int i=0; i<n; i++){
        cin>> A[i];
    }
    int k=0;
    for (int i=n-1; i>=0; i--){
        sum+=A[i]*pow(x, k);
        sum%=1000000007;
        k++;
    }
    cout<< sum;
}
