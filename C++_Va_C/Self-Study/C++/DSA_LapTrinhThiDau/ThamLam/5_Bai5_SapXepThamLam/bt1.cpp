#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>> n;
    int A[n]; int B[n];
    for (int i=0; i<n; i++){
        cin>> A[i];
        B[i]=A[i];
    }
    sort(B, B+n);
    for (int i=0; i<n; i++){
        if (!(A[i]==B[i] || A[i]==B[n-i-1])){
            cout<< "NO";
            return 0;
        }
    }
    cout<< "YES";
    return 0;
}
