#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>> n;
    int A[n];
    for (int i=0; i<n; i++) cin>> A[i];
    int max1=0, max2=0;
    for (int i=0; i<n; i++){
        if (A[i]>=max1){
            max2=max1;
            max1=A[i];
        } else if (A[i]>=max2){
            max2=A[i];
        }
    }
    cout<< max1<< " "<< max2;
    return 0;
}
