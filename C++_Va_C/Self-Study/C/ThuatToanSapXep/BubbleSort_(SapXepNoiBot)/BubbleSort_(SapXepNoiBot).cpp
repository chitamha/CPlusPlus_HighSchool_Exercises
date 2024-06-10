#include <iostream>
using namespace std;
int main(){
    freopen("INPUT.INP", "r", stdin);
    freopen("OUTPUT.OUT", "w", stdout);
    int n;
    cin>> n;
    int A[n];
    for (int i=0; i<n; i++){
        cin>> A[i];
    }
    for (int i=0; i<n-1; i++){
        for (int j=0; j<n-1-i; j++){
            if (A[j]>A[j+1]){
                int tam=A[j]; A[j]=A[j+1]; A[j+1]=tam;
            }
        }
    }
    for (int i=0; i<n; i++){
        cout<< A[i]<< " ";
    }
}
