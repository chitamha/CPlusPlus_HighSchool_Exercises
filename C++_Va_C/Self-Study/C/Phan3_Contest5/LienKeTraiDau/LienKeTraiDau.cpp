#include <iostream>
using namespace std;
int main(){
    int n;
    cin>> n;
    int A[n];
    for (int i=0; i<n; i++){
        cin>> A[i];
    }
    for (int i=0; i<n; i++){
        if ((A[i]*A[i+1]<0)||(A[i]*A[i-1]<0)){
            cout<< A[i]<< " ";
        }
        else if (i==0 && A[0]*A[1]<0) {cout<< A[0]<< " ";}
        else if (i==n-1 && A[n-1]*A[n-2]<0) {cout<< A[n-1];}
    }
}
