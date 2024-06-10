#include <iostream>
using namespace std;
int main(){
    int n, k;
    cin>> n>> k;
    int A[n];
    for (int i=0; i<n; i++){
        cin>> A[i];
    }
    int sum;
    for (int i=0; i<=n-k; i++){
        sum=0;
        for (int j=i; j<i+k; j++){
            sum+=A[j];
        }
        cout<< sum<< " ";
    }
}
