#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>> n;
    int A[n+2];
    for (int i=1; i<n+1; i++){
        cin>> A[i];
    }
    A[0]=2*A[1]-A[2];
    A[n+1]=2*A[n]-A[n-1];
    sort(A, A+n+2);
    for (int i=1; i<n+1; i++){
        if (A[i]-A[i-1]>=A[i+1]-A[i])
            cout<< A[i+1]-A[i]<< " ";
        else cout<< A[i]-A[i-1]<< " ";
        if (A[i]-A[1]>=A[n]-A[i])
            cout<< A[i]-A[1]<< " ";
        else cout<< A[n]-A[i];
        cout<< endl;
    }
}
